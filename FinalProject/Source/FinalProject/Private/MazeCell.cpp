// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCell.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

AMazeCell::AMazeCell() : GridSize(500.0f), WallHeight(500.0f)
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
	Floor -> SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> GridCellMesh(TEXT("/Script/Engine.StaticMesh'/Engine/VREditor/BasicMeshes/SM_Cube_01.SM_Cube_01'"));
	Floor -> SetStaticMesh(GridCellMesh.Object);

	TrapTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TrapTrigger -> SetupAttachment(RootComponent);

	NorthWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NorthWall"));
	NorthWall -> SetupAttachment(RootComponent);
	NorthWall -> SetStaticMesh(GridCellMesh.Object);

	SouthWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SouthWall"));
	SouthWall -> SetupAttachment(RootComponent);
	SouthWall -> SetStaticMesh(GridCellMesh.Object);

	EastWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EastWall"));
	EastWall -> SetupAttachment(RootComponent);
	EastWall -> SetStaticMesh(GridCellMesh.Object);

	WestWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WestWall"));
	WestWall -> SetupAttachment(RootComponent);
	WestWall -> SetStaticMesh(GridCellMesh.Object);
}

void AMazeCell::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	// FVector FloorScale = FVector(GridSize/100, GridSize/100, 0.2f);
	// Floor -> SetRelativeScale3D(FloorScale);

	float WallLength = GridSize;
	float WallThickness = GridSize * 0.1f;

	Floor -> SetRelativeScale3D(FVector(WallLength, WallLength, WallThickness) * 0.01f);


	if(bWestWallAvailable)
		WestWall -> SetRelativeScale3D(FVector(WallLength, WallThickness, WallHeight) * 0.01f);
	else
		WestWall -> SetRelativeScale3D(FVector(0,0,0));

	
	if(bSouthWallAvailable)
		SouthWall -> SetRelativeScale3D(FVector(WallThickness, WallLength, WallHeight) * 0.01f);
	else
		SouthWall -> SetRelativeScale3D(FVector(0,0,0));


	if(bNorthWallAvailable)
	{
		NorthWall -> SetRelativeScale3D(FVector(WallThickness, WallLength, WallHeight) * 0.01f);
		NorthWall -> SetRelativeLocation(FVector((WallLength - WallThickness), 0,0));
	}
	else
	{
		NorthWall -> SetRelativeScale3D(FVector(0,0,0));
	}


	if(bEastWallAvailable)
	{
		EastWall -> SetRelativeScale3D(FVector(WallLength, WallThickness, WallHeight) * 0.01f);
		EastWall -> SetRelativeLocation(FVector(0, (WallLength - WallThickness), 0));
	}
	else
	{
		EastWall -> SetRelativeScale3D(FVector(0,0,0));
	}
	
		
}


