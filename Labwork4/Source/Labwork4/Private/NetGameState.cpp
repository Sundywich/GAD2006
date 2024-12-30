// Fill out your copyright notice in the Description page of Project Settings.


#include "NetGameState.h"

#include "NetAvatar.h"
#include "NetPlayerState.h"
#include "Net/UnrealNetwork.h"

ANetGameState::ANetGameState() : WinningPlayer(-1)
{
	
}

void ANetGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ANetGameState, WinningPlayer);
}

void ANetGameState::OnRep_Winner()
{
	if(WinningPlayer >= 0)
	{
		OnVictory();
	}
}

void ANetGameState::TriggerRestart_Implementation()
{
	OnRestart();
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




