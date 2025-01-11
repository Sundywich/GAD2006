// Fill out your copyright notice in the Description page of Project Settings.


#include "TrapCell.h"

#include "FinalAvatar.h"
#include "Components/BoxComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ATrapCell::ATrapCell() : DamageAmount(10.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;

	CollisionBox -> OnComponentBeginOverlap.AddDynamic(this, &ATrapCell::OnOverlap);

	bIsActivated = false;
}

// Called when the game starts or when spawned
void ATrapCell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrapCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ATrapCell::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(!HasAuthority()) return;

	if(OtherActor && OtherActor != this)
	{
		DamagePlayer(OtherActor);
	}
}

void ATrapCell::DamagePlayer(AActor* OverlappedActor)
{
	AFinalAvatar* PlayerCharacter = Cast<AFinalAvatar>(OverlappedActor);

	if(PlayerCharacter)
	{
		// Damage the player

		if(!bIsActivated)
		{
			bIsActivated = true;
			OnRep_IsActivated();
		}
	}
}

void ATrapCell::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATrapCell, bIsActivated);
}


void ATrapCell::OnRep_IsActivated()
{
	if (bIsActivated)
	{
		UE_LOG(LogTemp, Log, TEXT("Trap is activated!"));

		// Add code for particle effects, sound, or material changes
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Trap is deactivated!")); // In case you later add deactivation
	}
}


