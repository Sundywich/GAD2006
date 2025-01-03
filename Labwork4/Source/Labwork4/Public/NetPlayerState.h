// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "NetGameInstance.h"
#include "NetPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class LABWORK4_API ANetPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_PlayerInfo)
	FSPlayerInfo Data;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
	int PlayerIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EPlayerTeam TeamID;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EGameResults Result;

private:
	UFUNCTION()
	void OnRep_PlayerInfo();
};
