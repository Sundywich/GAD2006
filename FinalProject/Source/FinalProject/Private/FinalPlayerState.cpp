// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalPlayerState.h"

#include "Net/UnrealNetwork.h"

AFinalPlayerState::AFinalPlayerState() : bHasRedKey(false), bHasGreenKey(false)
{
	bReplicates = true;
}

void AFinalPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFinalPlayerState, bHasRedKey);
	DOREPLIFETIME(AFinalPlayerState, bHasGreenKey);
}

