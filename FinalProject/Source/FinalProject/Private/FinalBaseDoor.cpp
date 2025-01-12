// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalBaseDoor.h"

// Sets default values
AFinalBaseDoor::AFinalBaseDoor()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);
	DoorMesh -> SetIsReplicated(true);
	
}

