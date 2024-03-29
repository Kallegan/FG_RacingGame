#pragma once

#include "FG_RacingGame/Powerup/RacePowerup.h"
#include "RaceBoostPowerup.generated.h"

class URaceCarMovementComponent;

UCLASS(Abstract)
class URaceBoostPowerup : public URacePowerup
{
	GENERATED_BODY()

public:
	void Setup_Implementation() override;
	void OnPowerupActivated_Implementation() override;
	bool ShouldDeactivate_Implementation() override;
	void TickActive_Implementation(float DeltaTime) override;
	
private:
	UPROPERTY()
	URaceCarMovementComponent* MoveComp;

	float BoostTime;
};