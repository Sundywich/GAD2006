// Fill out your copyright notice in the Description page of Project Settings.


#include "NetAvatar.h"
#include "GameFramework/CharacterMovementComponent.h"

ANetAvatar::ANetAvatar() : MovementScale(1.0f), RunSpeed(1200.0f), WalkSpeed(600.0f)
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
		SetRunState(true);
		UE_LOG(LogTemp, Display, TEXT("Server start Running"));
	}
	else
	{
		ServerSetRunState(true);
		UE_LOG(LogTemp, Display, TEXT("Server start Running"));
	}
}

void ANetAvatar::StopRunning()
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


void ANetAvatar::OnRep_bIsRunning()
{
	SetRunState(bIsRunning); // to be sure
	GEngine -> AddOnScreenDebugMessage(5, 3.0f, FColor::Blue, FString::Printf(TEXT("MaxSpeed: %f"), GetCharacterMovement() -> MaxWalkSpeed));
}

void ANetAvatar::ServerSetRunState_Implementation(bool _isRunning)
{
	SetRunState(_isRunning);
}

void ANetAvatar::SetRunState(bool bNewRunState)
{
	bIsRunning = bNewRunState;
	GetCharacterMovement()->MaxWalkSpeed = bIsRunning ? RunSpeed : WalkSpeed;
}


