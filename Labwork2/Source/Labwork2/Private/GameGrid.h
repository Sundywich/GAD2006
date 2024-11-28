// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSlot.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "GameGrid.generated.h"

UCLASS()
class AGameGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameGrid();

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGameSlot> GridClass;

	// How much row and column in a grid
	UPROPERTY(EditAnywhere)
	int NumRows;

	UPROPERTY(EditAnywhere)
	int NumCols;

	// We are having an array for child classes (slots)
	UPROPERTY(VisibleAnywhere)
	TArray<UChildActorComponent*> GridActors;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AGameSlot* GetSlot(FSGridPosition& Position);
	static AGameSlot* FindSlot(FSGridPosition Position);

private:
	// We'll have a one and only game grid in the scene, so make it static
	static AGameGrid* GameGrid;

};
