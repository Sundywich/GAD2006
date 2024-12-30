// Fill out your copyright notice in the Description page of Project Settings.


#include "NetGameMode.h"

#include <ios>

#include "NetBaseCharacter.h"
#include "NetGameState.h"
#include "NetPlayerState.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"
#include "Components/CapsuleComponent.h"
#include "Slate/SGameLayerManager.h"

ANetGameMode::ANetGameMode() : MaxTimer(30.0f)
{
	DefaultPawnClass = ANetBaseCharacter::StaticClass();
	PlayerStateClass = ANetPlayerState::StaticClass();
	GameStateClass = ANetGameState::StaticClass();
}


AActor* ANetGameMode::GetPlayerStart(FString Name, int Index)
{
	FName PSName;
	if(Index < 0)
	{
		PSName = *Name;
	}
	else
	{
		PSName = *FString::Printf(TEXT("%s%d"), *Name, Index % 4);
	}

	// Iterator thingy actually gets all of the APlayerStart actors in the world but for a for loop type. So that we can make things easier and cheaper.
	for(TActorIterator<APlayerStart> It(GWorld); It; ++It)
	{
		if(APlayerStart* PS = Cast<APlayerStart>(*It))
		{
			if (PS -> PlayerStartTag == PSName) return *It; // Then we return a playerstart 
		}
	}
	
	return nullptr;
}


AActor* ANetGameMode::ChoosePlayerStart_Implementation(AController* Player) 
{
	AActor* Start = AssignTeamAndPlayerStart(Player);
	return Start ? Start : Super::ChoosePlayerStart_Implementation(Player);
}

// This is also again to assign playerstart and also assign the joined player to a team
AActor* ANetGameMode::AssignTeamAndPlayerStart(AController* Player)
{
	AActor* Start = nullptr;
	ANetPlayerState* State = Player -> GetPlayerState<ANetPlayerState>();
	if(State)
	{

		if(TotalGames == 0)
		{
			State -> TeamID = TotalPlayerCount == 0 ? EPlayerTeam::TEAM_Blue : EPlayerTeam::TEAM_Red;
			State -> PlayerIndex = TotalPlayerCount++;
			AllPlayers.Add(Cast<APlayerController>(Player));
		}
		else
		{
			State -> TeamID = State -> Result == EGameResults::RESULT_Won ? EPlayerTeam::TEAM_Blue : EPlayerTeam::TEAM_Red;
		}

		if(State -> TeamID == EPlayerTeam::TEAM_Blue)
		{
			Start = GetPlayerStart("Blue", -1);
		}
		else
		{
			Start = GetPlayerStart("Red", PlayerStartIndex++);
		}
	}

	return Start;
} 


void ANetGameMode::AvatarsOverlapped(ANetAvatar* AvatarA, ANetAvatar* AvatarB)
{
	ANetGameState* GState = GetGameState<ANetGameState>();

	if(GState == nullptr || GState -> WinningPlayer >= 0) return;

	// Check player states
	ANetPlayerState* StateA = AvatarA -> GetPlayerState<ANetPlayerState>();
	ANetPlayerState* StateB = AvatarB -> GetPlayerState<ANetPlayerState>();
	if(StateA -> TeamID == StateB -> TeamID) return;

	// See which one is on the red team and assign it as the winning player *THIS PART IS IMPORTANT*
	if(StateA -> TeamID == EPlayerTeam::TEAM_Red)
	{
		GState -> WinningPlayer = StateA -> PlayerIndex;
	}
	else
	{
		GState -> WinningPlayer = StateB -> PlayerIndex;
	}

	// Close collisions to make sure this function doesn't run again
	AvatarA -> GetCapsuleComponent() -> SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	AvatarB -> GetCapsuleComponent() -> SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);

	// Run on victory
	GState -> OnVictory();

	for (APlayerController* Player : AllPlayers)
	{
		auto State = Player -> GetPlayerState<ANetPlayerState>();

		if(State -> TeamID == EPlayerTeam::TEAM_Blue)
		{
			State -> Result = EGameResults::RESULT_Lost;
		}
		else
		{
			State -> Result = EGameResults::RESULT_Won;
		}
	}

	FTimerHandle EndGameTimerHandle;
	GWorld -> GetTimerManager().SetTimer(EndGameTimerHandle, this, &ANetGameMode::EndGame, 2.5f, false);
}

void ANetGameMode::Timer()
{
	if(HasAuthority())
	{
		if (CurrentTimer > 0)
		{
			CurrentTimer--;
			GEngine -> AddOnScreenDebugMessage(-1, 2.5f, FColor::Red, FString::Printf(TEXT("Timer is %f"), CurrentTimer));
		}
		else
		{
			TimeIsFinished();
		}
	}
}

void ANetGameMode::TimeIsFinished_Implementation()
{
	ANetGameState* GState = GetGameState<ANetGameState>();
	if(GState == nullptr || GState -> WinningPlayer >= 0) return;

	for (APlayerController* Player : AllPlayers)
	{
		auto State = Player -> GetPlayerState<ANetPlayerState>();

		if(State -> TeamID == EPlayerTeam::TEAM_Blue)
		{
			// Set the game's winner
			GState -> WinningPlayer = State -> PlayerIndex;
			State -> Result = EGameResults::RESULT_Won;

			GEngine -> AddOnScreenDebugMessage(-1, 2.5f,FColor::Magenta, FString::Printf(TEXT("Winning Playe Index: %i"), GState -> WinningPlayer) );
			
		}
		else
		{
			State -> Result = EGameResults::RESULT_Lost;
		}
		
	}

	GState -> OnVictory();
	
	FTimerHandle EndGameTimerHandle;
	GWorld -> GetTimerManager().SetTimer(EndGameTimerHandle, this, &ANetGameMode::EndGame, 2.5f, false);
}

void ANetGameMode::BeginPlay()
{
	Super::BeginPlay();

	CurrentTimer = 30.0f;
	GWorld -> GetTimerManager().SetTimer(GameTimerHandle, this, &ANetGameMode::Timer, 1.0f, true);
}



void ANetGameMode::EndGame()
{
	PlayerStartIndex = 0;
	TotalGames++;
	GetGameState<ANetGameState>() -> WinningPlayer = -1;
	CurrentTimer = MaxTimer	;

	for(APlayerController* Player : AllPlayers)
	{
		APawn* Pawn = Player -> GetPawn();
		Player -> UnPossess();
		Pawn -> Destroy();
		Player -> StartSpot.Reset();
		RestartPlayer(Player);
	}

	ANetGameState* GState = GetGameState<ANetGameState>();
	GState -> TriggerRestart();
}






