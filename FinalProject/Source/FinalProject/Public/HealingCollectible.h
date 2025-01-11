// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealingCollectible.generated.h"

class UStaticMeshComponent;

UCLASS()
class FINALPROJECT_API AHealingCollectible : public AActor
{
	GENERATED_BODY()
	
public:
	AHealingCollectible();

	UPROPERTY(EditANywhere, BlueprintReadWrite)
	int32 HealingAmount;

	UFUNCTION(NetMulticast, Reliable)
	void MulticastDestroy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* HealMesh;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
