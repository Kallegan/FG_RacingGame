#include "RaceCar.h"

#include "RaceCarMovementComponent.h"
#include "Components/BoxComponent.h"
#include "FG_RacingGame/Powerup/RacePowerup.h"

ARaceCar::ARaceCar()
{
	PrimaryActorTick.bCanEverTick = true;
	
	BoxCollision =  CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Block);
	RootComponent = BoxCollision;

	MoveComp = CreateDefaultSubobject<URaceCarMovementComponent>(TEXT("MovementComponent"));
	
}

void ARaceCar::BeginPlay()
{
	Super::BeginPlay();	
}

void ARaceCar::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(Powerup)
	{
		FColor MsgColor = bPowerupActivated ? FColor::Green : FColor::Red;
		
		GEngine->AddOnScreenDebugMessage(
		INDEX_NONE,
		0.f,
		MsgColor,
		Powerup->GetClass()->GetName(),
		true,
		FVector2D(4.f)
		);

		if(bPowerupActivated)
		{
			Powerup->TickActive(DeltaSeconds);
			if(Powerup->ShouldDeactivate())
			{
				bPowerupActivated = false;
				Powerup = nullptr;
			}
		}
		
	}
}

void ARaceCar::SetupPlayerInputComponent(UInputComponent* InputComp)
{	
	InputComp->BindAxis(TEXT("Accelerate"), this, &ARaceCar::HandleAccelerateInput);
	InputComp->BindAxis(TEXT("TurnRight"), this, &ARaceCar::HandleTurnRightInput);
	
	InputComp->BindAction(TEXT("ActivatePowerup"),IE_Pressed,this, &ARaceCar::HandleActivatePowerup);

}

void ARaceCar::HandleActivatePowerup()
{
	if(IsValid(Powerup) && !bPowerupActivated)
	{
		Powerup->OnPowerupActivated();
		bPowerupActivated = true;
	}	
}

void ARaceCar::HandleAccelerateInput(float Value)
{	
	MoveComp->DriveForwardInput = Value;
}


void ARaceCar::HandleTurnRightInput(float Value)
{
	MoveComp->DriveSteerInput = Value;
}

void ARaceCar::EquipPowerup(URacePowerup* NewPowerup)
{
	Powerup = NewPowerup;
	Powerup->Setup();
}

