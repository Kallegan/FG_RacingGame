#pragma once

#include "FG_RacingGame/Powerup/RacePowerup.h"
#include "RaceBombPowerup.generated.h"

class ARaceBomb;


//marked as abstract since we want to use the blueprint when using not the base class.
UCLASS(Abstract)
class URaceBombPowerup : public URacePowerup
{
	GENERATED_BODY()

public:
	void OnPowerupActivated_Implementation() override;	

	UPROPERTY(EditDefaultsOnly, Category = Bomb)
	TSubclassOf<ARaceBomb> BombClass;

	UPROPERTY(EditAnywhere)
	float SpawnOffset = 400.f;
	
	
};
