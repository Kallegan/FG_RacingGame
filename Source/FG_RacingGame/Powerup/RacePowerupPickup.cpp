#include "RacePowerupPickup.h"
#include "Components/SphereComponent.h"
#include "RacePowerup.h"
#include "FG_RacingGame/Player/RaceCar.h"

ARacePowerupPickup::ARacePowerupPickup()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Root);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ARacePowerupPickup::HandleOverlap);
}

void ARacePowerupPickup::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		if(PowerupClassses.Num() > 0)
		{			
			auto PowerupRandClass = PowerupClassses[FMath::RandRange(0, PowerupClassses.Num() -1 )];

			ARaceCar* Car = Cast<ARaceCar>(OtherActor);
			if (!Car->HasEquipedPowerup())
			{
				Car->EquipPowerup(NewObject<URacePowerup>(Car, PowerupRandClass));			
				Destroy();
			}		
		}		
	
}
