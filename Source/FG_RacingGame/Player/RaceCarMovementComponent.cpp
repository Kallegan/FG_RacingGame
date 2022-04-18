#include "RaceCarMovementComponent.h"

URaceCarMovementComponent::URaceCarMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void URaceCarMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	AActor* Owner = GetOwner();

	Velocity += Owner->GetActorForwardVector() * Acceleration * DriveForwardInput * DeltaTime;

	FVector RollingVelocity = Velocity.ProjectOnTo(Owner->GetActorForwardVector());
	FVector GripVelocity = Velocity - RollingVelocity;

	RollingVelocity -= RollingVelocity * RollFriction * DeltaTime;
	GripVelocity -= GripVelocity * GripFriction * DeltaTime;

	
	Velocity = RollingVelocity + GripVelocity;

	float RemaningTime = DeltaTime;
	while(RemaningTime > 0.f)
	{
		FHitResult Hit;
		Owner->AddActorWorldOffset(Velocity * RemaningTime, true, &Hit);

		if(Hit.bBlockingHit)
		{
			if(Hit.bStartPenetrating)
			{
				Owner->AddActorWorldOffset(Hit.Normal * (Hit.PenetrationDepth +0.1f));
			}
			else
			{
				Velocity = FVector::VectorPlaneProject(Velocity, Hit.Normal);
				//Time is % time, 0-1, where 0.5 would be hit halfway. 1 would be full distance
				RemaningTime -= RemaningTime * Hit.Time;
			}					
		}
		else //didnt hit anything, we break the loop.
		{
			break;
		}
	}	
	float Speed = FVector::DotProduct(Velocity, Owner->GetActorForwardVector()); 
	Owner->AddActorWorldRotation(FRotator(0.f, DriveSteerInput * TurnSpeed * Speed * DeltaTime, 0.f));
}
//boost powerup. force happen over time(boost etc). Uses delta time.
void URaceCarMovementComponent::AddForce(const FVector& Force)
{
	Velocity += Force * GetWorld()->GetDeltaSeconds();
}
//impulse is instant. use for ex. explosion since it adds momentum in the same frame instead of multiple.
void URaceCarMovementComponent::AddImpulse(const FVector& Impulse)
{
	Velocity += Impulse;
}
