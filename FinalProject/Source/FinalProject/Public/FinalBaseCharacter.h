// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "Net/UnrealNetwork.h"
#include "FinalBaseCharacter.generated.h"

UENUM(BlueprintType)
enum class EBodyPart : uint8
{
	BP_Face = 0,
	BP_Hair = 1,
	BP_Chest = 2,
	BP_Hands = 3,
	BP_Legs = 4,
	BP_Beard = 5,
	BP_COUNT = 6,
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

	UPROPERTY(VisibleAnywhere)
	int Indices[(int)EBodyPart::BP_COUNT];

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isFemale;
};

USTRUCT(BlueprintType)
struct FSPlayerInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Nickname;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSBodyPartSelection BodyParts;

	bool Ready;
};

UCLASS()
class FINALPROJECT_API AFinalBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFinalBaseCharacter();
	
	virtual  void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ChangeBodyPart(EBodyPart index, int value, bool DirectSet);

	UFUNCTION(BlueprintCallable)
	void ChangeGender(bool isFemale);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_PlayerInfoChanged)
	FSBodyPartSelection PartSelection;

	UFUNCTION(Server, Reliable)
	void SubmitPlayerInfoToServer(FSPlayerInfo Info);

	UFUNCTION()
	void OnRep_PlayerInfoChanged();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	// Wearing system
	UFUNCTION(Server, Reliable)
	void ServerWearMeUp();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastWearMeUP();

	void WearMeUp();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsLevelStarted;

	FTimerHandle WearMeUpTimer;

	void StartForWearing();

private:
	UPROPERTY()
	USkeletalMeshComponent* PartFace;

	UPROPERTY()
	UStaticMeshComponent* PartHair;

	UPROPERTY()
	UStaticMeshComponent* PartBeard;

	UPROPERTY()
	UStaticMeshComponent* PartEyes;

	UPROPERTY()
	USkeletalMeshComponent* PartHands;
	
	UPROPERTY()
	USkeletalMeshComponent* PartLegs;

	static FSMeshAssetList* GetBodyPartList(EBodyPart part, bool isFemale);

	void UpdateBodyParts();
};
