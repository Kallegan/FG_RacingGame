#include "RaceBomb.h"

#include "DrawDebugHelpers.h"
#include "StaticMeshAttributes.h"
#include "Components/SphereComponent.h"


ARaceBomb::ARaceBomb()
{
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;

	Collision->OnComponentBeginOverlap.AddDynamic(this, &ARaceBomb::ExplosionBeginOverlap);
	
}

void ARaceBomb::BeginPlay()
{
	Super::BeginPlay();	
	
	BombVelocity = GetActorForwardVector() * 700.f;
	DetonationDelay = 2.f;	
}

void ARaceBomb::Tick(float DeltaSeconds)
{		
	AddActorWorldOffset(BombVelocity * DeltaSeconds);
	DetonationDelay -= DeltaSeconds;	

	 if(DetonationDelay <= 0.3f)
	 {
	 	if(bDetonating == false)
	 	{
	 		bDetonating = true;
	 		BombVelocity = GetActorUpVector() * 500.f;	 			 		
	 		Collision->SetSphereRadius(DetonationRadius);	 		
	 	}	 	

	 	if(DetonationDelay <0.f)
	 	{	 
	 		DrawDebugSphere(GetWorld(), GetActorLocation(), DetonationRadius, 12, FColor::Red,true, 1);
	 			 		
	        if (ExplosionTargets.Num() > 0)
	        {     
	        	for (AActor* Targets : ExplosionTargets)
	        	{
	        		FVector TargetLocation = Targets->GetActorLocation();
	        		ExplodingTargets(TargetLocation);
	        		Targets->Destroy();
	        	}	        	
	        }	 		
	 		ExplosionTargets.Empty();
	 		Destroy();
	 	}
	 }	
}

void ARaceBomb::ExplosionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	ExplosionTargets.Add(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("OVERLAPPING")) 
}

void ARaceBomb::ExplodingTargets_Implementation(FVector target) {}


