// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalBaseCollectible.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

AFinalBaseCollectible::AFinalBaseCollectible()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	CollectibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollectibleMesh"));
	CollectibleMesh -> SetupAttachment(RootComponent);
	CollectibleMesh -> SetIsReplicated(true);
}

void AFinalBaseCollectible::MulticastDestroy_Implementation()
{
	Destroy();
}

