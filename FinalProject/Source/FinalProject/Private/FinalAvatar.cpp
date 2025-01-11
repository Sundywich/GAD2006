// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalAvatar.h"

#include "HealingCollectible.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/CharacterMovementComponent.h"

AFinalAvatar::AFinalAvatar() : RunSpeed(600.0f), WalkSpeed(300.0f),  Stamina(100.0f), StaminaDrainRate(10.0f), Health(100)
{
	PrimaryActorTick.bCanEverTick = true;
		
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm -> SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera -> SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	GetCharacterMovement() -> MaxWalkSpeed = 300.0f;
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

	PlayerInputComponent -> BindAction("Interact", IE_Pressed, this, &AFinalAvatar::Interact);
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

void AFinalAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bIsRunning)
	{
		if(Stamina > 0.0f)
			Stamina -= DeltaTime * StaminaDrainRate;

		if(Stamina <= 0.0f)
			StopRunning();
	}
	else
	{
		if(Stamina < 100.0f)
			Stamina += DeltaTime * (StaminaDrainRate / 2);
	}
}



void AFinalAvatar::EarnDamage(int32 DamageAmount)
{
	if(HasAuthority())
	{
		Health -= DamageAmount;
		if(Health <= 0)
		{
			Health = 0;
			GameFinitoByDeath();
		}
	}
}

void AFinalAvatar::GameFinitoByDeath()
{
	ShowDeathScreen();

	for(FConstPlayerControllerIterator It = GetWorld() -> GetPlayerControllerIterator(); It; ++It)
	{
		APlayerController* PlayerController = It -> Get();
		AFinalAvatar* OtherPlayer = Cast<AFinalAvatar>(PlayerController -> GetPawn());

		if(OtherPlayer && OtherPlayer != this && OtherPlayer -> Health > 0)
		{
			OtherPlayer -> ShowVictoryScreen();
		}
	}

	GetWorld() -> GetFirstPlayerController() -> SetPause(true);
}

void AFinalAvatar::GameFinitoByVictory()
{
	ShowVictoryScreen();

	for(FConstPlayerControllerIterator It = GetWorld() -> GetPlayerControllerIterator(); It; ++It)
	{
		APlayerController* PlayerController = It -> Get();
		AFinalAvatar* OtherPlayer = Cast<AFinalAvatar>(PlayerController -> GetPawn());

		if(OtherPlayer && OtherPlayer != this)
		{
			OtherPlayer -> ShowDeathScreen();
		}
	}

	GetWorld() -> GetFirstPlayerController() -> SetPause(true);
}





void AFinalAvatar::ShowDeathScreen_Implementation()
{
	if(DeathScreenWidget)
	{
		UUserWidget* DeathScreen = CreateWidget<UUserWidget>(GetWorld(), DeathScreenWidget);
		
		if(DeathScreen){ DeathScreen -> AddToViewport(); }
	}
}

void AFinalAvatar::ShowVictoryScreen_Implementation()
{
	if(VictoryScreenWidget)
	{
		UUserWidget* VictoryScreen = CreateWidget<UUserWidget>(GetWorld(), VictoryScreenWidget);

		if(VictoryScreen){ VictoryScreen -> AddToViewport(); }
	}
}


void AFinalAvatar::Interact()
{
	if(HasAuthority())
	{
		ServerInteract();
	}
	else
	{
		ServerInteract();
	}
}

void AFinalAvatar::ServerInteract_Implementation()
{
	FVector Start = GetActorLocation();
	FVector ForwardVector = GetActorForwardVector();
	FVector End = Start + (ForwardVector * 500.f); // Line trace distance: 500 units

	FHitResult HitResult;

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECC_Visibility,
		CollisionParams
	);

	if (bHit)
	{
		AHealingCollectible* Collectible = Cast<AHealingCollectible>(HitResult.GetActor());
		if (Collectible)
		{
			// Heal the player
			Health = FMath::Clamp(Health + Collectible->HealingAmount, 0, 100);

			// Notify all clients to destroy the collectible
			Collectible->MulticastDestroy();
		}
	}
}

bool AFinalAvatar::ServerInteract_Validate()
{
	return true;
}










