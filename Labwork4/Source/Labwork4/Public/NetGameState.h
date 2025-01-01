// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "NetGameState.generated.h"

class ANetPlayerState;
/**
 * 
 */
UCLASS()
class LABWORK4_API ANetGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:

	ANetGameState();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_Winner) // every player is marked with an index in their playerstate
	int WinningPlayer;

	UFUNCTION()
	void OnRep_Winner();


	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_TimeIsOver)
	bool bTimeIsOver;

	UFUNCTION()
	void OnRep_TimeIsOver();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnVictoryRed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnVictoryBlue();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayOnPlayerLost(ANetPlayerState* PState);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayOnPlayerWon(ANetPlayerState* PState);

	UFUNCTION(BlueprintNativeEvent)
	void ShowResultMessageOnBlueVictory();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRestart();

	UFUNCTION(NetMulticast, Reliable)
	void TriggerRestart();

	UFUNCTION(BlueprintCallable)
	ANetPlayerState* GetPlayerStateByIndex(int PlayerIndex);

};
