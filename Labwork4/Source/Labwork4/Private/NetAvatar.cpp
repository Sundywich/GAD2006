// Fill out your copyright notice in the Description page of Project Settings.


#include "NetAvatar.h"
#include "GameFramework/CharacterMovementComponent.h"

ANetAvatar::ANetAvatar() : RunSpeed(1200.0f)
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
	AddMovementInput(ForwardDirection, Scale);
}

void ANetAvatar::MoveRight(float Scale)
{
	FRotator Rotation = GetController() -> GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(ForwardDirection, Scale);
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
		UpdateMovementSpeed();

		GEngine -> AddOnScreenDebugMessage(0, 3.0f, FColor::Blue, "Started Client Running");
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
		UpdateMovementSpeed();

		GEngine -> AddOnScreenDebugMessage(0, 3.0f, FColor::Blue, "Stopped Client Running");
	}
}


void ANetAvatar::OnRep_bIsRunning()
{
	UpdateMovementSpeed();
}

void ANetAvatar::UpdateMovementSpeed()
{
	if(GetCharacterMovement())
	{
		GetCharacterMovement() -> MaxWalkSpeed = bIsRunning ? RunSpeed : 600.0f;
	}
}

void ANetAvatar::ServerSetIsRunning_Implementation(bool _isRunning)
{
	bIsRunning = _isRunning;
}
