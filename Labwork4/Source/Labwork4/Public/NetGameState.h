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

	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnVictory();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnRestart();

	UFUNCTION(NetMulticast, Reliable)
	void TriggerRestart();

	UFUNCTION(BlueprintCallable)
	ANetPlayerState* GetPlayerStateByIndex(int PlayerIndex);

	UPROPERTY(BlueprintReadOnly)
	float GameTimer;

	UFUNCTION(BlueprintCallable)
	void TimerStart();

	UFUNCTION(NetMulticast, Reliable)
	void TimerStop();

	void UpdateTimer();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTimerDisplay(float Time);

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_RemainingTime)
	float RemainingTime;

	UFUNCTION()
	void OnRep_RemainingTime();

	FTimerHandle TimerHandle;

};
