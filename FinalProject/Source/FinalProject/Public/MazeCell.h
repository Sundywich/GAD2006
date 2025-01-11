// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeCell.generated.h"

class UBoxComponent;

UCLASS()
class FINALPROJECT_API AMazeCell : public AActor
{
	GENERATED_BODY()

public:
	AMazeCell();
	
	virtual void OnConstruction(const FTransform& Transform) override;
	
public:	

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* Floor;

	UPROPERTY(BlueprintReadWrite)
	UBoxComponent* TrapTrigger;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* NorthWall;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* SouthWall;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* EastWall;
	
	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* WestWall;
	


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GridSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WallHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bNorthWallAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSouthWallAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEastWallAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bWestWallAvailable;
	
};
