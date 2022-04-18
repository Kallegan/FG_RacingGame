#include "RaceStartLine.h"
#include "FG_RacingGame/Player/RaceCar.h"
#include "kismet/GameplayStatics.h"

ARaceStartLine::ARaceStartLine()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
}

void ARaceStartLine::BeginPlay()
{	
	Super::BeginPlay();

	FTransform SpawnTransform = GetActorTransform();
	
	for(int i = 0; i < NumberOfPlayers; i++)
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerControllerFromID(this, i);
		if(PlayerController == nullptr)
		{
			PlayerController = UGameplayStatics::CreatePlayer(this, i);
		}
		
		PlayerController->bAutoManageActiveCameraTarget = false;
		
		ARaceCar* Car = GetWorld()->SpawnActor<ARaceCar>(CarClass, SpawnTransform);
		PlayerController->Possess(Car);

		SpawnTransform.AddToTranslation(GetActorRightVector() * 200.f);
	}
}
