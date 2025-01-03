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

ANetGameMode::ANetGameMode() 
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

void ANetGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if(GetGameState<ANetGameState>() -> PlayerArray.Num() > 0)
		GetGameState<ANetGameState>() -> TimerStart();
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
			Start = GetTeamStartLocation(State -> TeamID);
		}
		else
		{
			State -> TeamID = State -> Result == EGameResults::RESULT_Won ? EPlayerTeam::TEAM_Blue : EPlayerTeam::TEAM_Red;
			Start = GetTeamStartLocation(State -> TeamID);
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

AActor* ANetGameMode::GetTeamStartLocation(EPlayerTeam TeamID)
{
	if (TeamID == EPlayerTeam::TEAM_Blue)
	{
		return GetPlayerStart("Blue", -1);
	}
	else if (TeamID == EPlayerTeam::TEAM_Red)
	{
		return GetPlayerStart("Red", PlayerStartIndex++);
	}
	return nullptr;
}

AActor* ANetGameMode::GetNextTeamStartLocation(ANetPlayerState* State)
{
	ANetPlayerState* NetPlayerState = State;
	if (NetPlayerState)
	{
		EGameResults PreviousResult = NetPlayerState->Result;
		EPlayerTeam NewTeamID = (NetPlayerState->TeamID == EPlayerTeam::TEAM_Blue) ? EPlayerTeam::TEAM_Red : EPlayerTeam::TEAM_Blue;

		if (PreviousResult == EGameResults::RESULT_Won || PreviousResult == EGameResults::RESULT_Lost)
		{
			NetPlayerState->TeamID = NewTeamID;
			return GetTeamStartLocation(NewTeamID);
		}
	}
	return nullptr;
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
	GState -> OnVictory();

	FTimerHandle EndGameTimerHandle;
	GWorld -> GetTimerManager().SetTimer(EndGameTimerHandle, this, &ANetGameMode::EndGame, 2.5f, false);
}

void ANetGameMode::TimeFinish_Implementation()
{
	ANetAvatar* AvatarA = nullptr;
	ANetAvatar* AvatarB = nullptr;

	for (APlayerController* Player : AllPlayers)
	{
		if (ANetAvatar* Avatar = GetPlayerAvatar(Player))
		{
			auto State = Avatar->GetPlayerState<ANetPlayerState>();
			if (State->TeamID == EPlayerTeam::TEAM_Red)
			{
				AvatarB = Avatar;
			}
			else
			{
				AvatarA = Avatar;
			}
		}
	}

	if (AvatarA && AvatarB)
	{
		SetWinningAvatar(AvatarA, AvatarB, true);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AvatarA or AvatarB is nullptr in TimeFinish_Implementation!"));
	}
}

ANetAvatar* ANetGameMode::GetPlayerAvatar(APlayerController* Player) const
{
	if (!Player)
	{
		return nullptr;
	}

	return Cast<ANetAvatar>(Player->GetPawn());
}

void ANetGameMode::SetWinningAvatar(ANetAvatar* AvatarA, ANetAvatar* AvatarB, bool bRedTeamWon)
{
	ANetGameState* GState = GetGameState<ANetGameState>();
	if (!IsValid(GState) || GState->WinningPlayer >= 0)
	{
		return;
	}

	GState->TimerStop();

	ANetPlayerState* StateA = AvatarA->GetPlayerState<ANetPlayerState>();
	ANetPlayerState* StateB = AvatarB->GetPlayerState<ANetPlayerState>();

	if (!IsValid(StateA) || !IsValid(StateB) || StateA->TeamID == StateB->TeamID)
	{
		return;
	}

	GState->WinningPlayer = (bRedTeamWon == (StateA->TeamID == EPlayerTeam::TEAM_Red))
		? StateA->PlayerIndex
		: StateB->PlayerIndex;

	UpdateAvatarCollision(AvatarA, AvatarB);
	UpdatePlayerResults(bRedTeamWon);

	GState->OnVictory();

	FTimerHandle EndGameTimerHandle;
	GWorld->GetTimerManager().SetTimer(EndGameTimerHandle, this, &ANetGameMode::EndGame, 2.5f, false);
}

void ANetGameMode::UpdateAvatarCollision(ANetAvatar* AvatarA, ANetAvatar* AvatarB) const
{
	if (AvatarA)
	{
		AvatarA->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	}

	if (AvatarB)
	{
		AvatarB->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	}
}

void ANetGameMode::UpdatePlayerResults(bool bRedTeamWon)
{
	for (APlayerController* Player : AllPlayers)
	{
		if (ANetPlayerState* State = Player->GetPlayerState<ANetPlayerState>())
		{
			State->Result = (State->TeamID == (bRedTeamWon ? EPlayerTeam::TEAM_Red : EPlayerTeam::TEAM_Blue))
				? EGameResults::RESULT_Won
				: EGameResults::RESULT_Lost;
		}
	}
}


void ANetGameMode::EndGame()
{
	PlayerStartIndex = 0;
	TotalGames++;
	GetGameState<ANetGameState>() -> WinningPlayer = -1;

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






