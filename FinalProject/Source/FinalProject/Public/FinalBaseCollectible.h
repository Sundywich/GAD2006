// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FinalBaseCollectible.generated.h"

UCLASS()
class FINALPROJECT_API AFinalBaseCollectible : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CollectibleMesh;

public:

	UFUNCTION(NetMulticast, Reliable)
	void MulticastDestroy();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCollect(AFinalAvatar* CollectedAvatar);

public:
	AFinalBaseCollectible();
};
