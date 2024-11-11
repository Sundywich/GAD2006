// Fill out your copyright notice in the Description page of Project Settings.


#include "COA_BaseCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACOA_BaseCharacter::ACOA_BaseCharacter() :
bDead(false),
Health(100.0f),
MaxHealth(100.f),
HealingRate(0.0f),
WalkSpeed(300.0f)

{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f,540.0f,0.0f);
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ACOA_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACOA_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(!bDead)
	{
		Health = FMath::Min(MaxHealth, Health + HealingRate * DeltaTime);
	}
}

// Called to bind functionality to input
void ACOA_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

