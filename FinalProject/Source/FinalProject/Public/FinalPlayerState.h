// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "FinalPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFinalPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AFinalPlayerState();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
public:
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Key/Door")
	bool bHasRedKey;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Key/Door")
	bool bHasGreenKey;

};
