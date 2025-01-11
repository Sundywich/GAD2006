// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalAvatar.h"
#include "GameFramework/CharacterMovementComponent.h"

AFinalAvatar::AFinalAvatar() : RunSpeed(1200.0f), WalkSpeed(600.0f), Health(100)
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

	PlayerInputComponent -> BindAction("Run", IE_Pressed, this, &AFinalAvatar::StartRunning);
	PlayerInputComponent -> BindAction("Run", IE_Released, this, &AFinalAvatar::StopRunning);
}

void AFinalAvatar::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFinalAvatar, bIsRunning);
	DOREPLIFETIME(AFinalAvatar, Health);
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

void AFinalAvatar::StartRunning()
{
	if(HasAuthority())
	{
		SetRunState(true);
		UE_LOG(LogTemp, Display, TEXT("Server start Running"));
	}
	else
	{
		ServerSetRunState(true);
		UE_LOG(LogTemp, Display, TEXT("Server start Running"));
	}
}

void AFinalAvatar::StopRunning()
{
	if(HasAuthority())
	{
		SetRunState(false);
		UE_LOG(LogTemp, Display, TEXT("Server stop Running"));
	}
	else
	{
		ServerSetRunState(false);
		UE_LOG(LogTemp, Display, TEXT("Client stop running"));
	}
}

void AFinalAvatar::OnRep_bIsRunning()
{
	SetRunState(bIsRunning);
}

void AFinalAvatar::ServerSetRunState_Implementation(bool _isRunning)
{
	SetRunState(_isRunning);
}

void AFinalAvatar::SetRunState(bool bNewRunState)
{
	bIsRunning = bNewRunState;
	GetCharacterMovement()->MaxWalkSpeed = bIsRunning ? RunSpeed : WalkSpeed;
}


void AFinalAvatar::TakeDamage(int32 DamageAmount)
{
	if(HasAuthority())
	{
		Health -= DamageAmount;
		if(Health <= 0)
		{
			Health = 0;
			GEngine -> AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("Player died"));
		}
		else
		{
			GEngine -> AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("Player health: %d"), Health);
		}
	}
}

void AFinalAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}






