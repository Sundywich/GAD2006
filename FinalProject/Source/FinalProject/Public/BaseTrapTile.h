// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTrapTile.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class FINALPROJECT_API ABaseTrapTile : public AActor
{
	GENERATED_BODY()

public:
	ABaseTrapTile();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* SpikeMesh;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(Server, Reliable)
	void Server_ActivateTrap();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ActivateTrap();

private:
	void ActivateTrap();
};
