#pragma once


#include "FG_RacingGame/Powerup/RacePowerup.h"
#include "RacePoopaShellPowerup.generated.h"

class ARacePoopaShell;

//marked as abstract since we want to use the blueprint when using not the base class.
UCLASS(Abstract)
class URacePoopaShellPowerup : public URacePowerup
{
	GENERATED_BODY()

public:
	void OnPowerupActivated_Implementation() override;

	UPROPERTY(EditDefaultsOnly, Category = Poopa)
	TSubclassOf<ARacePoopaShell> PoopaClass;
};
