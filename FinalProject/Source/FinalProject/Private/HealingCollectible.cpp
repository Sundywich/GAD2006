// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingCollectible.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

AHealingCollectible::AHealingCollectible() : HealingAmount(20)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	HealMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HealMesh"));
	HealMesh->SetupAttachment(RootComponent);
	HealMesh -> SetIsReplicated(true);
}

// Called when the game starts or when spawned
void AHealingCollectible::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHealingCollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHealingCollectible::MulticastDestroy_Implementation()
{
	Destroy();
}


