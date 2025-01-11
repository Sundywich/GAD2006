// Fill out your copyright notice in the Description page of Project Settings.


#include "NewTrapTile.h"

#include "FinalAvatar.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ANewTrapTile::ANewTrapTile() : bIsActivated(false)
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	bReplicates = true;
	
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	TriggerBox->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh -> SetupAttachment(RootComponent);
	Mesh -> SetIsReplicated(true);
	Mesh -> SetVisibility(false);
	Mesh -> SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

void ANewTrapTile::TriggerTrap(AActor* OtherActor)
{
	GEngine -> AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PressedTheTrigger"));

	if(!OtherActor || !Cast<AFinalAvatar>(OtherActor)) return;

	
	AFinalAvatar* PlayerAvatar = Cast<AFinalAvatar>(OtherActor);

	if(PlayerAvatar)
	{
		PlayerAvatar -> EarnDamage(20);
		
		if(HasAuthority())
		{
			ActivateTrap();
		}
		else
		{
			Server_ActivateTrap();
		}
	}

}

void ANewTrapTile::Server_ActivateTrap_Implementation()
{
	ActivateTrap();
}

void ANewTrapTile::ActivateTrap()
{
	Multicast_ActivateTrap();
}

void ANewTrapTile::Multicast_ActivateTrap_Implementation()
{
	Mesh -> SetVisibility(true);
	bIsActivated = true;
	GEngine -> AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("PressedTheTrap"));
}


void ANewTrapTile::OnConstruction(const FTransform& Transform)
{
	bIsActivated ? Mesh -> SetVisibility(true) : Mesh -> SetVisibility(false);
}



