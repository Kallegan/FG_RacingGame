#include "RaceBombPowerup.h"
#include "RaceBomb.h"

void URaceBombPowerup::OnPowerupActivated_Implementation()
{
	FTransform SpawnTransform = GetOwner()->GetActorTransform();
	SpawnTransform.SetLocation(SpawnTransform.GetLocation() + GetOwner()->GetActorForwardVector() * SpawnOffset);
	GetWorld()->SpawnActor(BombClass, &SpawnTransform);
}


