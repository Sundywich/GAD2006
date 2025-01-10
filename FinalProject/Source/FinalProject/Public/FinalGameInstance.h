// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalBaseCharacter.h"
#include "Engine/GameInstance.h"
#include "FinalGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API UFinalGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void Host(FString MapName, FSPlayerInfo PlayerInfo);

	UFUNCTION(BlueprintCallable)
	void Join(FString Address, FSPlayerInfo PlayerInfo);

	UPROPERTY(BlueprintReadWrite)
	FSPlayerInfo PlayerInfo;
};
