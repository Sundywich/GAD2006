// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "Net/UnrealNetwork.h"
#include "NetGameInstance.h"
#include "NetBaseCharacter.generated.h"

UENUM(BlueprintType)
enum class EBodyPart : uint8
{
	BP_Face = 0,
	BP_Hair = 1,
	BP_Chest = 2,
	BP_Hands = 3,
	BP_Legs = 4,
	BP_Beard = 5,
	BP_Eyebrow = 6,
	BP_BodyType = 7,
	BP_COUNT = 8,
};

USTRUCT(BlueprintType)
struct FSMeshAssetList : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<USkeletalMesh*> ListSkeletal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMesh*> ListStatic;
};

USTRUCT(BlueprintType)
struct FSBodyPartSelection
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	int Indices[(int)EBodyPart::BP_COUNT];

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isFemale;
};

UCLASS()
class ANetBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANetBaseCharacter();

	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BLueprintPure)
	FString GetCustomizationData();
	void ParseCustomizationData(FString Data);

	UFUNCTION(BlueprintCallable)
	void ChangeBodyPart(EBodyPart index, int value, bool DirectSet);

	UFUNCTION(BlueprintCallable)
	void ChangeGender(bool isFemale);
	
	UFUNCTION(Server, Reliable)
	void SubmitPlayerInfoToServer(FSPlayerInfo Info);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerInfoChanged();
	
	UFUNCTION()
	void CheckPlayerState();

	UFUNCTION()
	void CheckPlayerInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* PartFace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PartHair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PartBeard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PartEyes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* PartHands;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* PartLegs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PartEyebrow;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool PlayerInfoReceived;

private:

	int BodyPartIndices[(int)EBodyPart::BP_COUNT];

	void UpdateBodyParts();
	static FSMeshAssetList* GetBodyPartList(EBodyPart part, bool isFemale);
	
	FTimerHandle ClientDataCheckTimer;

};
