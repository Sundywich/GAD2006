// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTrapTile.h"

#include "FinalAvatar.h"
#include "Components/BoxComponent.h"

ABaseTrapTile::ABaseTrapTile()
{
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);

	// Create and configure the spike mesh
	SpikeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpikeMesh"));
	SpikeMesh->SetupAttachment(RootComponent);
	SpikeMesh->SetVisibility(false); // Initially hidden

	// Bind overlap event
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ABaseTrapTile::OnOverlapBegin);
}

void ABaseTrapTile::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseTrapTile::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && Cast<AFinalAvatar>(OtherActor)) // Check if it's the player
	{
		// Trigger server logic
		if (HasAuthority())
		{
			ActivateTrap();
		}
		else
		{
			Server_ActivateTrap();
		}
	}
}

void ABaseTrapTile::Server_ActivateTrap_Implementation()
{
	ActivateTrap();
}

void ABaseTrapTile::Multicast_ActivateTrap_Implementation()
{
	SpikeMesh->SetVisibility(true); // Show the spike
	UE_LOG(LogTemp, Warning, TEXT("I got damaged")); // Debug message for damage
}

void ABaseTrapTile::ActivateTrap()
{
	Multicast_ActivateTrap();
}







