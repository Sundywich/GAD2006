// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "TBPLayerController.h"
#include "Commands/Command.h"
#include "Commands/MoveCommand.h"

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

void AGameManager::OnActorClicked(AActor* Actor, FKey button)
{
	if(CurrentCommand.IsValid() && CurrentCommand -> IsExecuting()) return;

	AGameSlot* Slot = Cast<AGameSlot>(Actor);

	// Clicked on a non slot actor?
	if(!Slot) return;

	// Does the player clicked?
	if(!ThePlayer)
	{
		UE_LOG(LogTemp, Error, TEXT("No player unit detected!"))
		return;
	}

	// Empty slot?
	if(Slot -> Unit == nullptr)
	{
		// Move player
		TSharedRef<MoveCommand> Cmd =
			MakeShared<MoveCommand>(ThePlayer -> Slot -> GridPosition, Slot -> GridPosition);
		CommandPool.Add(Cmd);
		Cmd -> Execute();
		CurrentCommand = Cmd;
	}
}

bool AGameManager::UndoLastMove()
{
	
	if(CommandPool.IsEmpty())
	{
		GEngine -> AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No MoveCommand Remaining, Unable to Undo"));
		return false;
	}
	
	TSharedRef <MoveCommand> PreviousMove = StaticCastSharedRef<MoveCommand>(CommandPool.Pop());
	PreviousMove -> Revert();
		
	GEngine -> AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Undo Completed Successfully"));
	return true;

}


// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(CurrentCommand.IsValid())
	{
		CurrentCommand -> Update(DeltaTime);
	}

}

