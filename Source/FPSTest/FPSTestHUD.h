// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSTestHUD.generated.h"

UCLASS()
class AFPSTestHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFPSTestHUD();

	class UClass * hudWidgetClass;
	class UUserWidget * hudWidget;
	class UClass * mainWidgetClass;
	class UUserWidget * mainWidget;
	class UClass * resultsWidgetClass;
	class UUserWidget * resultsWidget;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

};

