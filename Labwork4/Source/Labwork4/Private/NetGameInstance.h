// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NetGameInstance.generated.h"

class ANetBaseCharacter;

UENUM(BlueprintType)
enum class EPlayerTeam : uint8
{
	TEAM_Unknown,
	TEAM_Blue,
	TEAM_Red,
};

UENUM(BlueprintType)
enum class EGameResults : uint8
{
	RESULT_Undefined,
	RESULT_Lost,
	RESULT_Won,
};

USTRUCT(BlueprintType)
struct FSPlayerInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Nickname;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CustomizationData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EPlayerTeam TeamID;
	
};

/**
 * 
 */
UCLASS()
class UNetGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Host (FString MapName, FSPlayerInfo PlayerInfo);

	UFUNCTION(BlueprintCallable)
	void Join (FSPlayerInfo PlayerInfo);

	UPROPERTY(BlueprintReadWrite)
	FSPlayerInfo PlayerInfo;

	
	FString IPAdressToJoin;

	UFUNCTION(BlueprintCallable)
	void SetIPAdressToJoin(FString IP);
};
