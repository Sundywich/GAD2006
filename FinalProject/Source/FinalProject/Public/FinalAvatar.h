// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "FinalAvatar.generated.h"

class UUserWidget;

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
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	void SetRunState(bool NewRunState);
	
	UFUNCTION(Server, Reliable)
	void ServerSetRunState(bool NewRunState);

	UFUNCTION()
	void OnRep_bIsRunning();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunSpeed;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float WalkSpeed;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_bIsRunning)
	bool bIsRunning;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StaminaDrainRate;

	virtual void Tick(float DeltaTime) override;

private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);

	void StartRunning();
	void StopRunning();

	//HP system
public:
	UPROPERTY(Replicated, BlueprintReadWrite)
	int32 Health;

	UFUNCTION(BlueprintCallable)
	void EarnDamage(int32 DamageAmount);

	// Widget System
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf <UUserWidget> DeathScreenWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf <UUserWidget> VictoryScreenWidget;

	UFUNCTION(BlueprintCallable, Client, Reliable)
	void ShowDeathScreen();
	
	UFUNCTION(BlueprintCallable, Client, Reliable)
	void ShowVictoryScreen();

	// Interaction system
public:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerInteract();

	void Interact();

public:
	UFUNCTION()
	void GameFinitoByDeath();

	UFUNCTION(BlueprintCallable)
	void GameFinitoByVictory();
	
};
