// Fill out your copyright notice in the Description page of Project Settings.


#include "NetGameMode.h"

#include <ios>
#include <MacTypes.h>

#include "NetBaseCharacter.h"
#include "NetGameState.h"
#include "NetPlayerState.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/GameMode.h"
#include "Slate/SGameLayerManager.h"

ANetGameMode::ANetGameMode() : MaxTimer(21.0f)
{
	bReplicates = true;
	
	DefaultPawnClass = ANetBaseCharacter::StaticClass();
	PlayerStateClass = ANetPlayerState::StaticClass();
	GameStateClass = ANetGameState::StaticClass();
}

void ANetGameMode::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void ANetGameMode::BeginPlay()
{
	Super::BeginPlay();

	CurrentTimer = MaxTimer;
	GWorld -> GetTimerManager().SetTimer(GameTimerHandle, this, &ANetGameMode::Timer, 1.0f, true);
}


void ANetGameMode::Timer()
{
	if(HasAuthority())
	{
		if(CurrentTimer > 0)
		{
			CurrentTimer--;
			GEngine -> AddOnScreenDebugMessage(-1, 2.5f, FColor::Emerald, FString::Printf(TEXT("Current Timer: %f"), CurrentTimer));
		}
		else
		{
			TimerIsFinished();
		}
	}
}

void ANetGameMode::TimerIsFinished()
{
	ANetGameState* GState = GetGameState<ANetGameState>();
	if(GState == nullptr || GState -> WinningPlayer >= 0) return;

	// Change time is over so clients can run OnRep
	GState -> bTimeIsOver = true;
	
	for (APlayerController* Player : AllPlayers)
	{
		auto State = Player -> GetPlayerState<ANetPlayerState>();

		if(State -> TeamID == EPlayerTeam::TEAM_Red)
		{
			State -> Result = EGameResults::RESULT_Lost;
		}
		else
		{
			State -> Result = EGameResults::RESULT_Won;
		}
	}

	// Run on victory (Because server can't run OnRep on itself)
	GState -> OnVictoryBlue();

	GWorld -> GetTimerManager().PauseTimer(GameTimerHandle);

	FTimerHandle EndGameTimerHandle;
	GWorld -> GetTimerManager().SetTimer(EndGameTimerHandle, this, &ANetGameMode::EndGame, 2.5f, false);
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

	// Run on victory
	GState -> OnVictoryRed();

	FTimerHandle EndGameTimerHandle;
	GWorld -> GetTimerManager().SetTimer(EndGameTimerHandle, this, &ANetGameMode::EndGame, 2.5f, false);
}

void ANetGameMode::EndGame()
{
	PlayerStartIndex = 0;
	TotalGames++;
	GetGameState<ANetGameState>() -> WinningPlayer = -1;

	// I added
	GetGameState<ANetGameState>() -> bTimeIsOver = false;
	CurrentTimer = MaxTimer;
	GWorld -> GetTimerManager().UnPauseTimer(GameTimerHandle);

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






