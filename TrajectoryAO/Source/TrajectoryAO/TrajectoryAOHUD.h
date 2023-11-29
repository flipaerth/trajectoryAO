// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TrajectoryAOHUD.generated.h"

UCLASS()
class ATrajectoryAOHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATrajectoryAOHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

