#pragma once

#include "GameFramework/Pawn.h"
#include "RaceCar.generated.h"

class UBoxComponent;
class URaceCarMovementComponent;
class URacePowerup;

UCLASS()
class ARaceCar : public APawn
{
	GENERATED_BODY()

public:
	ARaceCar();

	virtual void BeginPlay() override;
	void Tick(float DeltaSeconds) override;

	void SetupPlayerInputComponent(UInputComponent* InputComp) override;

	void HandleActivatePowerup();
	void HandleAccelerateInput(float Value);
	void HandleTurnRightInput(float Value);

	void EquipPowerup(URacePowerup* NewPowerup);
	bool HasEquipedPowerup() { return Powerup != nullptr; }
	
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere)
	URaceCarMovementComponent* MoveComp;
	
	UPROPERTY()
	URacePowerup* Powerup = nullptr;
	bool bPowerupActivated = false;	
	
};
