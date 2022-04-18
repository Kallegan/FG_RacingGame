#include "RaceCamera.h"
#include "Camera/CameraComponent.h"

ARaceCamera::ARaceCamera()
{

	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(Root);
}

void ARaceCamera::BeginPlay()
{
	Super::BeginPlay();
		
	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	Controller->SetViewTarget(this);
}

void ARaceCamera::Tick(float DeltaTime)
{
	if (FollowActor == nullptr)
		return;	
	
	FVector Location = GetActorLocation();
	Location = FMath::Lerp(Location, FollowActor->GetActorLocation(), FollowSpeed * DeltaTime);

	SetActorLocation(Location);
}
