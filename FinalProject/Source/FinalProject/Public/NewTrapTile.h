// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewTrapTile.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class FINALPROJECT_API ANewTrapTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewTrapTile();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* TriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

public:
	UFUNCTION(BlueprintCallable)
	void TriggerTrap(AActor* OtherActor);

	virtual void OnConstruction(const FTransform& Transform) override;

	UFUNCTION(Server, Reliable)
	void Server_ActivateTrap();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ActivateTrap();

	void ActivateTrap();

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsActivated;

};
