// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FG_RacingGameGameModeBase.generated.h"

class UUserWidget;

UCLASS()
class FG_RACINGGAME_API AFG_RacingGameGameModeBase : public AGameModeBase
{
	AFG_RacingGameGameModeBase();
	GENERATED_BODY()

public:
	void BeginPlay() override;
	

	UPROPERTY(EditDefaultsOnly, Category = Widgets)
	TSubclassOf<UUserWidget> OverlayWidgetClass;
	
};
