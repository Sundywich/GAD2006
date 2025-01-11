// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalBaseCollectible.h"
#include "FinalHealingCollectible.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFinalHealingCollectible : public AFinalBaseCollectible
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	int32 HealingAmount;

	AFinalHealingCollectible();

	
	
};
