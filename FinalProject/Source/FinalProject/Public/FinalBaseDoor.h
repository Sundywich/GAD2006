// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalAvatar.h"
#include "FinalBaseKey.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "FinalBaseDoor.generated.h"

UCLASS()
class FINALPROJECT_API AFinalBaseDoor : public AActor
{
	GENERATED_BODY()
	
public:
	AFinalBaseDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpened;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DoorMesh;

	UFUNCTION(BlueprintImplementableEvent)
	void DoorInteract(AFinalAvatar* InteractingAvatar);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFinalBaseKeyType KeyType;
	
};
