#pragma once

#include "GameFramework/Actor.h"
#include "RaceBomb.generated.h"

class USphereComponent;

UCLASS()
class ARaceBomb : public AActor
{
	GENERATED_BODY()
public:
	ARaceBomb();

	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Collision;

	UFUNCTION()
	void ExplosionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
	float DetonationRadius = 1000.f;
	
	FVector BombVelocity;	
	float DetonationDelay;	
	bool bDetonating = false;	

	UPROPERTY()
	TArray<AActor*> ExplosionTargets;
    
    //used in blueprint for custom death effect depending on what type of bomb used. Ex. acid = green etc, ice = blue etc.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ExplodingTargets(FVector target);
};

