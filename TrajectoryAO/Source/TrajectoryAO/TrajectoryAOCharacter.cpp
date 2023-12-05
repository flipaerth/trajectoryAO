// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrajectoryAOCharacter.h"
#include "TrajectoryAOProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId
#include "DrawDebugHelpers.h"
#include "Math/Vector.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ATrajectoryAOCharacter

ATrajectoryAOCharacter::ATrajectoryAOCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(false);			// otherwise won't be visible in the multiplayer
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P, FP_Gun, and VR_Gun 
	// are set in the derived blueprint asset named MyCharacter to avoid direct content references in C++.

	// Create VR Controllers.
	R_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("R_MotionController"));
	R_MotionController->MotionSource = FXRMotionControllerBase::RightHandSourceId;
	R_MotionController->SetupAttachment(RootComponent);
	L_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("L_MotionController"));
	L_MotionController->SetupAttachment(RootComponent);

	// Create a gun and attach it to the right-hand VR controller.
	// Create a gun mesh component
	VR_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VR_Gun"));
	VR_Gun->SetOnlyOwnerSee(false);			// otherwise won't be visible in the multiplayer
	VR_Gun->bCastDynamicShadow = false;
	VR_Gun->CastShadow = false;
	VR_Gun->SetupAttachment(R_MotionController);
	VR_Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	VR_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("VR_MuzzleLocation"));
	VR_MuzzleLocation->SetupAttachment(VR_Gun);
	VR_MuzzleLocation->SetRelativeLocation(FVector(0.000004, 53.999992, 10.000000));
	VR_MuzzleLocation->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));		// Counteract the rotation of the VR gun model.

	// Uncomment the following line to turn motion controllers on by default:
	//bUsingMotionControllers = true;
}

float ATrajectoryAOCharacter::GetDisplacement(float Time, float ProjectileGravity, float ProjectileSpeed) {
	return ProjectileSpeed * Time + 0.5f * ProjectileGravity * (Time * Time);
}

void ATrajectoryAOCharacter::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, "Press the 1, 2, 3, 4, or 5 number keys to change projectile speed.");
	int32 IntSpeed = FMath::RoundToInt(projectileSpeed); // Round the float to the nearest integer - ChatGPT helped with this line of code and specifically the %d in the text
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("The current projectile speed is: %d"), IntSpeed));

	// Getting the location of the gun
	FRotator SpawnRotation = GetControlRotation();
	FVector start = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset); //FP_Gun->GetComponentLocation();

	// Get the forward vector of the camera
	FVector ForwardVector = FirstPersonCameraComponent->GetForwardVector();

	// projectilespeed is the bullet's velocity, so the actual initial velocity is "projectilespeed in the direction of player's forward"
	FVector forward_velocity = FP_Gun->GetRightVector() * projectileSpeed;

	/*
	 * EQUATION: d (displacement) = vi(initial velocity) * t(time) + 1/2 * a(acceloration) * t^2
	 */

	// Initialize previousPoint outside the loop
	FVector previousPoint = start;

	for (float time = 0; time < maxTime; time += precision) {

		// Checking to see if the loop is running
		//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, "Hello World");

		// get how much we've moved at each chunk of time
		//float displacement = projectileSpeed * time + 0.5f + projectileGravity * (time * time); // equation/formula here
		//FVector displacementVector = FVector(0.0f, 0.0f, displacement);

		float dispX = GetDisplacement(time, 0, forward_velocity.X);
		float dispY = GetDisplacement(time, 0, forward_velocity.Y);
		float dispZ = GetDisplacement(time, projectileGravity, forward_velocity.Z);
		FVector actualDisplacement = FVector(dispX, dispY, dispZ);

		FVector currentPoint = start + actualDisplacement;
		//FVector previousPoint = currentPoint;


		//*************************************************************************************************************************
		// This code is to stop the debug line when it hits an object
		FHitResult OutHit;
		FCollisionQueryParams CollisionParams;

		// If something is hit, this puts it as the outhit hit result variable
		bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, previousPoint, currentPoint, ECC_Visibility, CollisionParams);

		if (isHit) {
			if (OutHit.bBlockingHit) {

				// Calculate the line direction
				FVector lineDir = (currentPoint - previousPoint).GetSafeNormal();

				// Calculate the surface normal
				FVector normal = OutHit.ImpactNormal.GetSafeNormal();

				// Used ChatGPT to help with this part - I struggled the absolute MOST here for days before I used it, but I realize that goes against the point of the assignment
				FVector reflection = lineDir - 2 * FVector::DotProduct(lineDir, normal) * normal; // I had a similar implementation a few hours prior
				reflection.Normalize();

				// Calculate the point for the reflection line
				FVector reflectionPoint = OutHit.ImpactPoint + reflection * reflectionOffset;

				DrawDebugLine(GetWorld(), OutHit.ImpactPoint, reflectionPoint, lineColorFromGun, false, 0.1f);

				// Draw debug line up to the hit location
				DrawDebugLine(GetWorld(), previousPoint, OutHit.ImpactPoint, lineColorFromGun, false, 0.1f);
				break; // Stop the loop when it hits an object - ChatGPT addition for optimization
			}
		}
		else {
			// Draw debug line
			DrawDebugLine(GetWorld(), previousPoint, currentPoint, lineColorFromGun, false, 0.1f);
		}
		//*************************************************************************************************************************


		// draw line here
		//DrawDebugLine(GetWorld(), previousPoint, currentPoint, lineColorFromGun, false, 0.1f);

		// Update previousPoint for the next iteration
		previousPoint = currentPoint;
	}

	// Draw Debug Line to visualize the line trace
	//DrawDebugLine(GetWorld(), start, end, lineColorFromGun, false, 0.1f);
}

void ATrajectoryAOCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	// Show or hide the two versions of the gun based on whether or not we're using motion controllers.
	if (bUsingMotionControllers)
	{
		VR_Gun->SetHiddenInGame(false, true);
		Mesh1P->SetHiddenInGame(true, true);
	}
	else
	{
		VR_Gun->SetHiddenInGame(true, true);
		Mesh1P->SetHiddenInGame(false, true);
	}
}

void ATrajectoryAOCharacter::projSpeedChange1() {
	projectileSpeed = 1000.0f;
}

void ATrajectoryAOCharacter::projSpeedChange2() {
	projectileSpeed = 3000.0f;
}

void ATrajectoryAOCharacter::projSpeedChange3() {
	projectileSpeed = 5000.0f;
}

void ATrajectoryAOCharacter::projSpeedChange4() {
	projectileSpeed = 7000.0f;
}

void ATrajectoryAOCharacter::projSpeedChange5() {
	projectileSpeed = 10000.0f;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATrajectoryAOCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATrajectoryAOCharacter::OnFire);

	// Enable touchscreen input
	EnableTouchscreenMovement(PlayerInputComponent);

	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ATrajectoryAOCharacter::OnResetVR);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &ATrajectoryAOCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATrajectoryAOCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ATrajectoryAOCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATrajectoryAOCharacter::LookUpAtRate);

	// Setting up projectile speed change inputs - this is my code
	PlayerInputComponent->BindAction("Speed1", IE_Pressed, this, &ATrajectoryAOCharacter::projSpeedChange1);
	PlayerInputComponent->BindAction("Speed2", IE_Pressed, this, &ATrajectoryAOCharacter::projSpeedChange2);
	PlayerInputComponent->BindAction("Speed3", IE_Pressed, this, &ATrajectoryAOCharacter::projSpeedChange3);
	PlayerInputComponent->BindAction("Speed4", IE_Pressed, this, &ATrajectoryAOCharacter::projSpeedChange4);
	PlayerInputComponent->BindAction("Speed5", IE_Pressed, this, &ATrajectoryAOCharacter::projSpeedChange5);
}

void ATrajectoryAOCharacter::OnFire()
{
	// try and fire a projectile
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			if (bUsingMotionControllers)
			{
				const FRotator SpawnRotation = VR_MuzzleLocation->GetComponentRotation();
				const FVector SpawnLocation = VR_MuzzleLocation->GetComponentLocation();
				World->SpawnActor<ATrajectoryAOProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
			}
			else
			{
				const FRotator SpawnRotation = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				ATrajectoryAOProjectile* proj = ProjectileClass.GetDefaultObject();
				proj->SetProjectileSpeed(projectileSpeed);
				projectileGravity = GetWorld()->GetGravityZ();

				// spawn the projectile at the muzzle
				World->SpawnActor<ATrajectoryAOProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			}
		}
	}

	// try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

void ATrajectoryAOCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ATrajectoryAOCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == true)
	{
		return;
	}
	if ((FingerIndex == TouchItem.FingerIndex) && (TouchItem.bMoved == false))
	{
		OnFire();
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void ATrajectoryAOCharacter::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == false)
	{
		return;
	}
	TouchItem.bIsPressed = false;
}

//Commenting this section out to be consistent with FPS BP template.
//This allows the user to turn without using the right virtual joystick

//void ATrajectoryAOCharacter::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location)
//{
//	if ((TouchItem.bIsPressed == true) && (TouchItem.FingerIndex == FingerIndex))
//	{
//		if (TouchItem.bIsPressed)
//		{
//			if (GetWorld() != nullptr)
//			{
//				UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
//				if (ViewportClient != nullptr)
//				{
//					FVector MoveDelta = Location - TouchItem.Location;
//					FVector2D ScreenSize;
//					ViewportClient->GetViewportSize(ScreenSize);
//					FVector2D ScaledDelta = FVector2D(MoveDelta.X, MoveDelta.Y) / ScreenSize;
//					if (FMath::Abs(ScaledDelta.X) >= 4.0 / ScreenSize.X)
//					{
//						TouchItem.bMoved = true;
//						float Value = ScaledDelta.X * BaseTurnRate;
//						AddControllerYawInput(Value);
//					}
//					if (FMath::Abs(ScaledDelta.Y) >= 4.0 / ScreenSize.Y)
//					{
//						TouchItem.bMoved = true;
//						float Value = ScaledDelta.Y * BaseTurnRate;
//						AddControllerPitchInput(Value);
//					}
//					TouchItem.Location = Location;
//				}
//				TouchItem.Location = Location;
//			}
//		}
//	}
//}

void ATrajectoryAOCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ATrajectoryAOCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ATrajectoryAOCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATrajectoryAOCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool ATrajectoryAOCharacter::EnableTouchscreenMovement(class UInputComponent* PlayerInputComponent)
{
	if (FPlatformMisc::SupportsTouchInput() || GetDefault<UInputSettings>()->bUseMouseForTouch)
	{
		PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATrajectoryAOCharacter::BeginTouch);
		PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this, &ATrajectoryAOCharacter::EndTouch);

		//Commenting this out to be more consistent with FPS BP template.
		//PlayerInputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ATrajectoryAOCharacter::TouchUpdate);
		return true;
	}
	
	return false;
}
