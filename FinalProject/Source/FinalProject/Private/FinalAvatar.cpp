// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalAvatar.h"
#include "GameFramework/CharacterMovementComponent.h"

AFinalAvatar::AFinalAvatar()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm -> SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera -> SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void AFinalAvatar::BeginPlay()
{
	Super::BeginPlay();

	Camera -> bUsePawnControlRotation = false;
	SpringArm -> bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;
	GetCharacterMovement() -> bOrientRotationToMovement = true;
}

void AFinalAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent -> BindAxis("Turn", this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent -> BindAxis("Lookup", this, &ACharacter::AddControllerPitchInput);

	PlayerInputComponent -> BindAxis("MoveForward", this, &AFinalAvatar::MoveForward);
	PlayerInputComponent -> BindAxis("MoveRight", this, &AFinalAvatar::MoveRight);
}

void AFinalAvatar::MoveForward(float Amount)
{
	FRotator Rotation = GetController() -> GetControlRotation();
	FRotator YawRotation (0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, Amount);
}

void AFinalAvatar::MoveRight(float Amount)
{
	FRotator Rotation = GetController() -> GetControlRotation();
	FRotator YawRotation (0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(ForwardDirection, Amount);
}




