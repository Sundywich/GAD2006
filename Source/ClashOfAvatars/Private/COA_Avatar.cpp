// Fill out your copyright notice in the Description page of Project Settings.


#include "COA_Avatar.h"

#include "GameFramework/CharacterMovementComponent.h"

// Constructor function, works before all the functions.
ACOA_Avatar::ACOA_Avatar() :
RunSpeed(600.0f),
Stamina(99.0f),
MaxStamina(100.0f),
StaminaDrainRate(10.0f),
StaminaGainRate(10.0f),
bRunning(false),
bStaminaDrained(false)
{
	// Tick enabled
	PrimaryActorTick.bCanEverTick = true;
	
	// Camera setup
	mSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	mSpringArm->TargetArmLength = 300.0f;
	mSpringArm->SetupAttachment(RootComponent);

	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	mCamera->SetupAttachment(mSpringArm, USpringArmComponent::SocketName);

	// Set controller rotations
	mCamera-> bUsePawnControlRotation = false;
	mSpringArm -> bUsePawnControlRotation = true;

	// Set pawn controller rotation yaw
	bUseControllerRotationYaw = false; 
}

void ACOA_Avatar::Tick(float DeltaTime)
{
	// Will update stamina here
	if(bRunning && !bStaminaDrained)
	{
		if(GetCharacterMovement() -> MovementMode == MOVE_Walking)
		{
			Stamina -= StaminaDrainRate * DeltaTime;

			if(Stamina <= 0.0f)
			{
				bRunning = false;
				bStaminaDrained = true;
				UpdateMovementParams();
			}
		}
	}
	else if (!bRunning)
	{
		if(Stamina < MaxStamina)
		{
			Stamina += StaminaGainRate * DeltaTime;
		}
		else
		{
			bStaminaDrained = false;
			Stamina = MaxStamina;
		}
	}
}


// An override function
void ACOA_Avatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent -> BindAxis("Turn", this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent -> BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);

	PlayerInputComponent -> BindAxis("MoveForward",this,&ACOA_Avatar::MoveForward);
	PlayerInputComponent -> BindAxis("MoveRight",this,&ACOA_Avatar::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACOA_Avatar::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACOA_Avatar::Jump);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ACOA_Avatar::RunPressed);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ACOA_Avatar::RunReleased);
}

void ACOA_Avatar::UpdateMovementParams()
{
	// Will set the correct movement speed based on stamina state
	if(!bStaminaDrained)
	{
		if(bRunning)
		{
			GetCharacterMovement() -> MaxWalkSpeed = RunSpeed;
		}
		else
		{
			GetCharacterMovement() -> MaxWalkSpeed = WalkSpeed;
		}
	}
	else
	{
		GetCharacterMovement() -> MaxWalkSpeed = WalkSpeed;
	}

}


void ACOA_Avatar::RunPressed()
{
	if(Stamina > 0.0f && !bStaminaDrained)
	{
		bRunning = true;
		UpdateMovementParams();
	}
}

void ACOA_Avatar::RunReleased()
{
	if(bRunning)
	{
		bRunning = false;
		UpdateMovementParams();
	}
}

void ACOA_Avatar::MoveForward(float Value)
{
	FRotator Rotation = GetController() -> GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, Value);
}

void ACOA_Avatar::MoveRight(float Value)
{
	FRotator Rotation = GetController() -> GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, Value);
}

