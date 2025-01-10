// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "FinalAvatar.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFinalAvatar : public AFinalBaseCharacter
{
	GENERATED_BODY()

public:

	AFinalAvatar();

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);
};
