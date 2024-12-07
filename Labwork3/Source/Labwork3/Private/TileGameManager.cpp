// Fill out your copyright notice in the Description page of Project Settings.


#include "TileGameManager.h"
#include "TilePlayerController.h"
#include "GameFramework/PlayerInput.h"

// Sets default values
ATileGameManager::ATileGameManager() : GridSize(100), GridOffset(0 ,0,0.5f), MapExtendsInGrids(25)
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	GridSelection = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GridMesh"));
	GridSelection->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		PlaneMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Plane.Plane'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface>
		GridMaterial(TEXT("/Script/Engine.Material'/Game/UI/MAT_GridSlot.MAT_GridSlot'"));

	GridSelection -> SetStaticMesh(PlaneMesh.Object);
	GridSelection -> SetMaterial(0, GridMaterial.Object);
	GridSelection -> SetCollisionEnabled(ECollisionEnabled::NoCollision);

	TilePreviewMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TilePreviewMesh"));
	TilePreviewMesh -> SetupAttachment(RootComponent);
	TilePreviewMesh -> SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ATileGameManager::BeginPlay()
{
	Super::BeginPlay();

	if(auto PlayerController = Cast<ATilePlayerController>(GWorld -> GetFirstPlayerController()))
	{
		PlayerController -> GameManager = this;
	}

	UpdateTilePreviewMesh();
}

// Called every frame
void ATileGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATileGameManager::UpdateTilePreviewMesh()
{
	if(TileTypes.IsValidIndex(CurrentTileIndex))
	{
		TilePreviewMesh -> SetStaticMesh(TileTypes[CurrentTileIndex] -> BaseMesh);
		TilePreviewMesh -> SetWorldScale3D(TileTypes[CurrentTileIndex] -> InstancedMesh -> GetRelativeScale3D()); // To match its scale
	}
}


void ATileGameManager::OnActorInteraction(AActor* HitActor, FVector& Location, bool IsPressed)
{
	// No tile types?
	if(TileTypes.Num() == 0) return;

	FVector GridLoc = GridOffset;
	GridLoc.X += FMath::GridSnap(Location.X, GridSize);
	GridLoc.Y += FMath::GridSnap(Location.Y, GridSize);
	GridLoc.Z += Location.Z;
	
	UPlayerInput* Input = GWorld -> GetFirstPlayerController() -> PlayerInput;

	if(Input -> WasJustPressed(EKeys::LeftMouseButton))
	{
		int GridX = GridLoc.X / GridSize + MapExtendsInGrids;
		int GridY = GridLoc.Y / GridSize + MapExtendsInGrids;

		if(GridX < 0 || GridY < 0 || GridX >= MapExtendsInGrids * 2 || GridY >= MapExtendsInGrids * 2)
		{
			// Can not place out of the grid
			return;
		}

		// Already a tile here?
		if(Map[GridX][GridY] != nullptr) return;

		if(TileTypes.IsValidIndex(CurrentTileIndex))
		{
			ATileBase* SelectedTile = TileTypes[CurrentTileIndex];
			Map[GridX][GridY] = SelectedTile;

			FTransform TileTransform(GridLoc + GridOffset);
			TileTransform.SetRotation(TilePreviewMesh -> GetRelativeRotation().Quaternion()); // Didn't wanted to mess with transform structure 
			SelectedTile -> InstancedMesh -> AddInstance(SelectedTile -> InstancedMesh -> GetRelativeTransform() * TileTransform, true);
		}

		UE_LOG(LogTemp, Warning, TEXT("Hit: %s - %f,%f,%f"), HitActor ? *HitActor -> GetActorLabel() : TEXT("None"), Location.X, Location.Y, Location.Z);
	}
	else if(Input -> WasJustPressed(EKeys::RightMouseButton))
	{
		TilePreviewMesh -> SetRelativeRotation(TilePreviewMesh -> GetRelativeRotation() + FRotator(0,90,0));
	}
	else if(Input -> WasJustPressed(EKeys::MouseScrollDown))
	{
		CurrentTileIndex = (CurrentTileIndex + 1) % TileTypes.Num();
		UpdateTilePreviewMesh();
		
		UE_LOG(LogTemp, Warning, TEXT("TileType: %s"), *TileTypes[CurrentTileIndex] -> GetActorLabel());
	}
	else if(Input -> WasJustPressed(EKeys::MouseScrollUp))
	{
		CurrentTileIndex = (CurrentTileIndex - 1 + TileTypes.Num()) % TileTypes.Num();
		UpdateTilePreviewMesh();
		
		UE_LOG(LogTemp, Warning, TEXT("TileType: %s"), *TileTypes[CurrentTileIndex] -> GetActorLabel());
	}
	else
	{
		GridSelection -> SetWorldLocation(GridLoc + GridOffset);
		TilePreviewMesh -> SetWorldLocation(GridLoc + GridOffset);
	}
}


