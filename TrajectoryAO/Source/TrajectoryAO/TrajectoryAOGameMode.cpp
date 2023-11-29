// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrajectoryAOGameMode.h"
#include "TrajectoryAOHUD.h"
#include "TrajectoryAOCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATrajectoryAOGameMode::ATrajectoryAOGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATrajectoryAOHUD::StaticClass();
}
