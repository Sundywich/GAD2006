// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NetBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "NetAvatar.generated.h"

/**
 * 
 */
UCLASS()
class LABWORK4_API ANetAvatar : public ANetBaseCharacter
{
	GENERATED_BODY()

public:

	ANetAvatar();

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadWrite)
	float MovementScale;

	void SetRunState(bool bNewRunState);

	UFUNCTION(Server, Reliable)
	void ServerSetRunState(bool _isRunning);

	UFUNCTION()
	void OnRep_bIsRunning();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunSpeed;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float WalkSpeed;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_bIsRunning)
	bool bIsRunning;
	
private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void StartRunning();
	void StopRunning();
};
