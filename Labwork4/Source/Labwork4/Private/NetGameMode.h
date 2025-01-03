// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NetAvatar.h"
#include "NetGameMode.generated.h"

class ANetGameState;
class ANetPlayerState;
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
	void EndGame();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual void PostLogin(APlayerController* NewPlayer) override;

	UFUNCTION(NetMulticast, Reliable)
	void TimeFinish();

	ANetAvatar* GetPlayerAvatar(APlayerController* Player) const;

	UFUNCTION()
	void SetWinningAvatar(ANetAvatar* AvatarA, ANetAvatar* AvatarB, bool bRedTeamWon);

	void UpdateAvatarCollision(ANetAvatar* AvatarA, ANetAvatar* AvatarB) const;

	void UpdatePlayerResults(bool bRedTeamWon);

	
private:
	int TotalPlayerCount;
	int TotalGames;
	int PlayerStartIndex;

	TArray<APlayerController*> AllPlayers;

	AActor* GetPlayerStart(FString Name, int Index);
	AActor* AssignTeamAndPlayerStart(AController* Player);
	AActor* GetTeamStartLocation(EPlayerTeam TeamID);
	AActor* GetNextTeamStartLocation(ANetPlayerState* State);
	
};
