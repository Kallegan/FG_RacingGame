#include "RacePoopaShell.h"
#include "Components/SphereComponent.h"


ARacePoopaShell::ARacePoopaShell()
{
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
}

void ARacePoopaShell::BeginPlay()
{
	Super::BeginPlay();
	
	ShellVelocity = GetActorForwardVector() * 1500.f;	
}

void ARacePoopaShell::Tick(float DeltaSeconds)
{
	FHitResult Hit;
	AddActorWorldOffset(ShellVelocity * DeltaSeconds, true, &Hit);

	if(Hit.bBlockingHit)
	{
		ShellVelocity = ShellVelocity.MirrorByVector(Hit.Normal);
	}
}
