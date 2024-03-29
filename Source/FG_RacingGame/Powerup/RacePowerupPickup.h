#pragma once

#include "GameFramework/Actor.h"
#include "RacePowerupPickup.generated.h"

class USphereComponent;
class URacePowerup;

UCLASS()
class ARacePowerupPickup : public AActor
{
	GENERATED_BODY()

public:
	ARacePowerupPickup();

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	UPROPERTY(EditDefaultsOnly, Category= Powerups)
	TArray<TSubclassOf<URacePowerup>> PowerupClassses;
};