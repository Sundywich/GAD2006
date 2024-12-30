// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NetAvatar.h"
#include "NetGameMode.generated.h"
/**
 * 
 */
UCLASS()
class ANetGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANetGameMode();

	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	UFUNCTION(BlueprintCallable)
	void AvatarsOverlapped(ANetAvatar* AvatarA, ANetAvatar* AvatarB);

	UFUNCTION(BlueprintCallable)
	void Timer();

	UFUNCTION(Server, Reliable)
	void TimeIsFinished();

	UFUNCTION(BlueprintCallable)
	void EndGame();
	
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxTimer;

	UPROPERTY()
	float CurrentTimer;

	UPROPERTY()
	FTimerHandle GameTimerHandle;
	
private:
	int TotalPlayerCount;
	int TotalGames;
	int PlayerStartIndex;

	TArray<APlayerController*> AllPlayers;

	AActor* GetPlayerStart(FString Name, int Index);

	AActor* AssignTeamAndPlayerStart(AController* Player);
	
};
