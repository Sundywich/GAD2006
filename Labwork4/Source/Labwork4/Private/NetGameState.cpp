// Fill out your copyright notice in the Description page of Project Settings.


#include "NetGameState.h"

#include "NetAvatar.h"
#include "NetPlayerState.h"
#include "Audio/ISoundHandleSystem.h"
#include "Net/UnrealNetwork.h"

ANetGameState::ANetGameState() : WinningPlayer(-1), bTimeIsOver(false)
{
	bReplicates = true;
}

void ANetGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ANetGameState, WinningPlayer);

	// I Added
	DOREPLIFETIME(ANetGameState, bTimeIsOver);
}


void ANetGameState::OnRep_Winner()
{
	if(WinningPlayer >= 0)
	{
		OnVictoryRed();
	}
}

void ANetGameState::OnRep_TimeIsOver()
{
	if(bTimeIsOver)
	{
		OnVictoryBlue();
	}
}

void ANetGameState::TriggerRestart_Implementation()
{
	OnRestart();
}

void ANetGameState::OnVictoryBlue_Implementation()
{
	for(auto Player : PlayerArray)
	{
		ANetPlayerState* PState = Cast<ANetPlayerState>(Player);

		switch(PState -> Data.TeamID)
		{
		case EPlayerTeam::TEAM_Unknown:
			break;

		case EPlayerTeam::TEAM_Blue:
			PlayOnPlayerWon(PState);
			break;

		case EPlayerTeam::TEAM_Red:
			PlayOnPlayerWon(PState);
			break;
		}
	}

	ShowResultMessageOnBlueVictory();
	
}

void ANetGameState::ShowResultMessageOnBlueVictory_Implementation()
{
	
}



ANetPlayerState* ANetGameState::GetPlayerStateByIndex(int PlayerIndex) // Give me the state of the player that's equal to this index 
{
	for(APlayerState* PS : PlayerArray)
	{
		ANetPlayerState* State = Cast<ANetPlayerState>(PS);
		if(State && State->PlayerIndex == PlayerIndex)
		{
			return State;
		}
	}

	return nullptr;
}





