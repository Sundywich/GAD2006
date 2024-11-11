// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "COA_BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "COA_Avatar.generated.h"

/**
 * 
 */
UCLASS()
class CLASHOFAVATARS_API ACOA_Avatar : public ACOA_BaseCharacter
{
	GENERATED_BODY()

public:
	// Constructor function
	ACOA_Avatar();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	UCameraComponent* mCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	USpringArmComponent* mSpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	float RunSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	float Stamina;

	UPROPERTY(EditAnywhere, Category = "Character")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Character")
	float StaminaDrainRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	float StaminaGainRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	bool bRunning;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	bool bStaminaDrained;
	
	
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void RunPressed();
	void RunReleased();
	void UpdateMovementParams();
};

