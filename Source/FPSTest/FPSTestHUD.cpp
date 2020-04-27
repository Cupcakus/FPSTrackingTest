// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FPSTestHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "FPSTestCharacter.h"

AFPSTestHUD::AFPSTestHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> hudWidgetObj(TEXT("/Game/HUD/FPSHUD"));
	static ConstructorHelpers::FClassFinder<UUserWidget> mainWidgetObj(TEXT("/Game/HUD/MainMenu"));
	static ConstructorHelpers::FClassFinder<UUserWidget> resultsWidgetObj(TEXT("/Game/HUD/ResultsMenu"));

	if (hudWidgetObj.Succeeded())
	{
		hudWidgetClass = hudWidgetObj.Class;
	}
	else
	{
		// hudWidgetObj not found
		hudWidgetClass = nullptr;
	}

	if (mainWidgetObj.Succeeded())
	{
		mainWidgetClass = mainWidgetObj.Class;
	}
	else
	{
		mainWidgetClass = nullptr;
	}

	if (resultsWidgetObj.Succeeded())
	{
		resultsWidgetClass = resultsWidgetObj.Class;
	}
	else
	{
		resultsWidgetClass = nullptr;
	}
}

void AFPSTestHUD::BeginPlay()
{
	Super::BeginPlay();

	if (hudWidgetClass) {
		// the player controller should be constructed by now so we can get a reference to it
		hudWidget = CreateWidget<UUserWidget>(this->GetOwningPlayerController(), this->hudWidgetClass);
		hudWidget->AddToViewport();
		hudWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (mainWidgetClass) {
		// the player controller should be constructed by now so we can get a reference to it
		mainWidget = CreateWidget<UUserWidget>(this->GetOwningPlayerController(), this->mainWidgetClass);
		mainWidget->AddToViewport();
		
	}


	if (resultsWidgetClass) {
		// the player controller should be constructed by now so we can get a reference to it
		resultsWidget = CreateWidget<UUserWidget>(this->GetOwningPlayerController(), this->resultsWidgetClass);
		resultsWidget->AddToViewport();
		resultsWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AFPSTestHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AFPSTestCharacter* character = static_cast<AFPSTestCharacter*>(this->GetOwningPlayerController()->GetCharacter());
	if (character->CurrentState == ETrackingModeState::Training)
	{
		hudWidget->SetVisibility(ESlateVisibility::Visible);
		mainWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	else if (character->CurrentState == ETrackingModeState::Results)
	{
		hudWidget->SetVisibility(ESlateVisibility::Hidden);
		mainWidget->SetVisibility(ESlateVisibility::Hidden);
		resultsWidget->SetVisibility(ESlateVisibility::Visible);
	}
}
