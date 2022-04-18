#include "RacePoopaShellPowerup.h"
#include "RacePoopaShell.h"

void URacePoopaShellPowerup::OnPowerupActivated_Implementation()
{
	FTransform SpawnTransform = GetOwner()->GetActorTransform();
	GetWorld()->SpawnActor(PoopaClass, &SpawnTransform);
}
