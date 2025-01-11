// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalBaseCollectible.h"
#include "GameFramework/Actor.h"
#include "FinalBaseKey.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EFinalBaseKeyType : uint8
{
	RedKey,
	GreenKey
};

UCLASS()
class FINALPROJECT_API AFinalBaseKey : public AFinalBaseCollectible
{
	GENERATED_BODY()

public:	
	AFinalBaseKey();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFinalBaseKeyType KeyType;
	
};
