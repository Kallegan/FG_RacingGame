// Copyright Epic Games, Inc. All Rights Reserved.


#include "FG_RacingGameGameModeBase.h"
#include "Blueprint/UserWidget.h"

AFG_RacingGameGameModeBase::AFG_RacingGameGameModeBase()
{
	DefaultPawnClass = nullptr;
}

void AFG_RacingGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	auto* Overlay = NewObject<UUserWidget>(this, OverlayWidgetClass);
	Overlay->AddToViewport();
	
}
