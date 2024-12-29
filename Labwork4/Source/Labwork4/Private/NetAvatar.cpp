// Fill out your copyright notice in the Description page of Project Settings.


#include "NetAvatar.h"
#include "GameFramework/CharacterMovementComponent.h"

ANetAvatar::ANetAvatar() : MovementScale(1.0f), RunSpeed(1200.0f)
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm-> SetupAttachment(RootComponent);

	Camera =  CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void ANetAvatar::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ANetAvatar, bIsRunning);
}

void ANetAvatar::BeginPlay()
{
	Super::BeginPlay();

	Camera -> bUsePawnControlRotation = false;
	SpringArm -> bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;
	GetCharacterMovement() -> bOrientRotationToMovement = true;
}

void ANetAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent -> BindAxis("Turn", this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent -> BindAxis("Lookup", this, &ACharacter::AddControllerPitchInput);

	PlayerInputComponent -> BindAxis("MoveForward", this, &ANetAvatar::MoveForward);
	PlayerInputComponent -> BindAxis("MoveRight", this, &ANetAvatar::MoveRight);

	PlayerInputComponent -> BindAction("Run", IE_Pressed, this, &ANetAvatar::StartRunning);
	PlayerInputComponent -> BindAction("Run", IE_Released, this, &ANetAvatar::StopRunning);
}


void ANetAvatar::MoveForward(float Scale)
{
	FRotator Rotation = GetController() -> GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, MovementScale * Scale);
}

void ANetAvatar::MoveRight(float Scale)
{
	FRotator Rotation = GetController() -> GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(ForwardDirection, MovementScale * Scale);
}

void ANetAvatar::StartRunning()
{
	if(HasAuthority())
	{
		bIsRunning = true;
		UpdateMovementSpeed();

		GEngine -> AddOnScreenDebugMessage(0, 3.0f, FColor::Green, "Started Running");
	}
	else
	{
		ServerSetIsRunning(true);
		OnRep_bIsRunning();
		
		FString BoolText = bIsRunning ? TEXT("True") : TEXT("False");
		GEngine->AddOnScreenDebugMessage(
			-1,                             // Unique Key (-1 means it creates a new message every time)
			5.0f,                           // Duration (seconds)
			FColor::Green,                  // Text color
			FString::Printf(TEXT("bIsRunning: %s"), *BoolText) // Format the message
		);
		
	}
		
}

void ANetAvatar::StopRunning()
{
	if(HasAuthority())
	{
		bIsRunning = false;
		UpdateMovementSpeed();

		GEngine -> AddOnScreenDebugMessage(0, 3.0f, FColor::Red, "Stopped Running");
	}
	else
	{
		ServerSetIsRunning(false);
		OnRep_bIsRunning();
		// UpdateMovementSpeed();

		FString BoolText = bIsRunning ? TEXT("True") : TEXT("False");
		GEngine->AddOnScreenDebugMessage(
			-1,                             // Unique Key (-1 means it creates a new message every time)
			5.0f,                           // Duration (seconds)
			FColor::Green,                  // Text color
			FString::Printf(TEXT("bIsRunning: %s"), *BoolText) // Format the message
		);
	}
}


void ANetAvatar::OnRep_bIsRunning()
{
	UpdateMovementSpeed();
	GEngine -> AddOnScreenDebugMessage(5, 3.0f, FColor::Blue, FString::Printf(TEXT("MaxSpeed: %f"), GetCharacterMovement() -> MaxWalkSpeed));
}

void ANetAvatar::UpdateMovementSpeed()
{
	if(GetCharacterMovement())
	{
		if(bIsRunning)
		{
			GetCharacterMovement() -> MaxWalkSpeed = 1200.0f;
		}
		else
		{
			GetCharacterMovement() -> MaxWalkSpeed = 600.0f;
		}
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
}

void ANetAvatar::ServerSetIsRunning_Implementation(bool _isRunning)
{
	bIsRunning = _isRunning;
}

