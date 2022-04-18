#pragma once

#include "Camera/CameraComponent.h"
#include "FG_RacingGame/Player/RaceCarMovementComponent.h"
#include "GameFramework/Actor.h"
#include "RaceCamera.generated.h"

UCLASS()
class ARaceCamera : public AActor
{
	GENERATED_BODY()

public:
	ARaceCamera();

	virtual void BeginPlay() override;
	void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category="Camera Follow|Advanced")
	float FollowSpeed = 5.f;	
	
	UPROPERTY(EditAnywhere, Category="Camera Follow")
	AActor* FollowActor;
	
};
