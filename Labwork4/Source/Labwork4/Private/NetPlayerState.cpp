// Fill out your copyright notice in the Description page of Project Settings.


#include "NetPlayerState.h"
#include "NetBaseCharacter.h"
#include "Net/UnrealNetwork.h"

void ANetPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ANetPlayerState, Data);
	DOREPLIFETIME(ANetPlayerState, PlayerIndex);

	// I added
	DOREPLIFETIME(ANetPlayerState, Result);
}

// Runs after client player recieved their PlayerInfo
void ANetPlayerState::OnRep_PlayerInfo()
{
	ANetBaseCharacter* Char = Cast<ANetBaseCharacter>(GetPawn());
	if(Char)
	{
		Char -> PlayerInfoReceived = true;
	}
	else
	{
		// To make a loop for double triple checking
		FTimerHandle PlayerInfoUpdateTimer;
		GWorld -> GetTimerManager().SetTimer(PlayerInfoUpdateTimer, this, &ANetPlayerState::OnRep_PlayerInfo, 0.25f, false);
	}
}



