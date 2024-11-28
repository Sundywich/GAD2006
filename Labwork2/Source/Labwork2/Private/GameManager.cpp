// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "TBPLayerController.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();

	if(auto PlayerController = GWorld -> GetFirstPlayerController<ATBPLayerController>())
	{
		PlayerController -> GameManager = this;
	}

	if(Levels.IsValidIndex(CurrentLevel))
	{
		CreateLevelActors(Levels[CurrentLevel]);
	}
}

void AGameManager::CreateLevelActors(FSLevelInfo& Info)
{
	ThePlayer = nullptr;

	for(auto UnitInfo : Info.Units)
	{
		if(AGameSlot* Slot = GameGrid -> GetSlot(UnitInfo.StartPosition))
		{
			Slot -> SpawnUnitHere(UnitInfo.UnitClass);
			if(Slot -> Unit && Slot -> Unit -> IsControlledByThePlayer())
			{
				ThePlayer = Slot -> Unit;
			}
		}
	}
}


// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

