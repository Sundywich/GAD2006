// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalBaseCharacter.h"

#include "FinalGameInstance.h"


static UDataTable* SBodyParts = nullptr;

static const TCHAR* BodyPartNames[] =
{
	TEXT("Face"),
	TEXT("Hair"),
	TEXT("Chest"),
	TEXT("Hands"),
	TEXT("Legs"),
	TEXT("Beard")
};


AFinalBaseCharacter::AFinalBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	PartFace = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Face"));
	PartFace -> SetupAttachment(GetMesh());
	PartFace -> SetLeaderPoseComponent(GetMesh());

	PartHands = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hands"));
	PartHands -> SetupAttachment(GetMesh());
	PartHands -> SetLeaderPoseComponent(GetMesh());

	PartLegs = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Legs"));
	PartLegs -> SetupAttachment(GetMesh());
	PartLegs -> SetLeaderPoseComponent(GetMesh());

	PartHair = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hair"));
	PartHair -> SetupAttachment(PartFace, FName("headSocket"));
	
	PartBeard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Beard"));
	PartBeard -> SetupAttachment(PartFace, FName("headSocket"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SK_Eyes(TEXT("/Script/Engine.StaticMesh'/Game/StylizedModularChar/Meshes/SM_Eyes.SM_Eyes'"));

	PartEyes = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Eyes"));
	PartEyes -> SetupAttachment(PartFace, FName("headSocket"));
	PartEyes -> SetStaticMesh(SK_Eyes.Object);

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_BodyParts(TEXT("/Script/Engine.DataTable'/Game/Blueprints/DT_BodyParts.DT_BodyParts'"));
	SBodyParts = DT_BodyParts.Object;
}

void AFinalBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(IsLocallyControlled())
	{
		UFinalGameInstance* Instance = Cast<UFinalGameInstance>(GetWorld() -> GetGameInstance());
		if(Instance && Instance -> PlayerInfo.Ready)
		{
			SubmitPlayerInfoToServer(Instance->PlayerInfo);
		}
	}

	GWorld -> GetTimerManager().SetTimer(WearMeUpTimer, this, &AFinalBaseCharacter::StartForWearing, 0.25f, false);
}

void AFinalBaseCharacter::StartForWearing()
{
	if(!bIsLevelStarted) return;

	else
	{
		if(HasAuthority())
		{
			WearMeUp();
		}
		else
		{
			ServerWearMeUp();
		}
	}
}

void AFinalBaseCharacter::WearMeUp()
{
	MulticastWearMeUP();
}

void AFinalBaseCharacter::ServerWearMeUp_Implementation()
{
	WearMeUp();
}

void AFinalBaseCharacter::MulticastWearMeUP_Implementation()
{
	UFinalGameInstance* Instance = Cast<UFinalGameInstance>(GetWorld() -> GetGameInstance());

	if(Instance)
	{
		int NewIndices[(int)EBodyPart::BP_COUNT];
		NewIndices[0] = Instance -> PlayerInfo . BodyParts . Indices[0];
		NewIndices[1] = Instance -> PlayerInfo . BodyParts . Indices[1];
		NewIndices[2] = Instance -> PlayerInfo . BodyParts . Indices[2];
		NewIndices[3] = Instance -> PlayerInfo . BodyParts . Indices[3];
		NewIndices[4] = Instance -> PlayerInfo . BodyParts . Indices[4];
		NewIndices[5] = Instance -> PlayerInfo . BodyParts . Indices[5];
		
		ChangeBodyPart(EBodyPart::BP_Face, NewIndices[0], true);
		ChangeBodyPart(EBodyPart::BP_Beard, NewIndices[5], true);
		ChangeBodyPart(EBodyPart::BP_Chest, NewIndices[2], true);
		ChangeBodyPart(EBodyPart::BP_Hair, NewIndices[1], true);
		ChangeBodyPart(EBodyPart::BP_Hands, NewIndices[3], true);
		ChangeBodyPart(EBodyPart::BP_Legs, NewIndices[4], true);

		GWorld -> GetTimerManager().PauseTimer(WearMeUpTimer);
	}
}

void AFinalBaseCharacter::OnRep_PlayerInfoChanged()
{
	UpdateBodyParts();
}

void AFinalBaseCharacter::SubmitPlayerInfoToServer_Implementation(FSPlayerInfo Info)
{
	PartSelection = Info.BodyParts;

	if(HasAuthority())
	{
		OnRep_PlayerInfoChanged();
	}
}

void AFinalBaseCharacter::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFinalBaseCharacter, PartSelection);
}

void AFinalBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFinalBaseCharacter::ChangeBodyPart(EBodyPart index, int value, bool DirectSet)
{
	FSMeshAssetList* List = GetBodyPartList(index, PartSelection.isFemale);
	if(List == nullptr) return;

	int CurrentIndex = PartSelection.Indices[(int)index];

	if(DirectSet)
	{
		CurrentIndex = value;
	}
	else
	{
		CurrentIndex += value;
	}

	int Num = List -> ListSkeletal.Num() + List -> ListStatic.Num();

	if(CurrentIndex < 0)
	{
		CurrentIndex += Num;
	}
	else
	{
		CurrentIndex %= Num;
	}


	PartSelection.Indices[(int)index] = CurrentIndex;

	switch(index)
	{
	case EBodyPart::BP_Face: PartFace -> SetSkeletalMeshAsset(List -> ListSkeletal[CurrentIndex]); break;
	case EBodyPart::BP_Beard: PartBeard -> SetStaticMesh(List -> ListStatic[CurrentIndex]); break;
	case EBodyPart::BP_Chest: GetMesh() -> SetSkeletalMeshAsset(List -> ListSkeletal[CurrentIndex]); break;
	case EBodyPart::BP_Hair: PartHair -> SetStaticMesh(List -> ListStatic[CurrentIndex]); break;
	case EBodyPart::BP_Hands: PartHands -> SetSkeletalMeshAsset(List -> ListSkeletal[CurrentIndex]); break;
	case EBodyPart::BP_Legs: PartLegs -> SetSkeletalMeshAsset(List -> ListSkeletal[CurrentIndex]); break;
	}
}

void AFinalBaseCharacter::ChangeGender(bool _isFemale)
{
	PartSelection.isFemale = _isFemale;
	UpdateBodyParts();
}

void AFinalBaseCharacter::UpdateBodyParts()
{
	ChangeBodyPart(EBodyPart::BP_Face, 0, false);
	ChangeBodyPart(EBodyPart::BP_Beard, 0, false);
	ChangeBodyPart(EBodyPart::BP_Chest, 0, false);
	ChangeBodyPart(EBodyPart::BP_Hair, 0, false);
	ChangeBodyPart(EBodyPart::BP_Hands, 0, false);
	ChangeBodyPart(EBodyPart::BP_Legs, 0, false);
}

FSMeshAssetList* AFinalBaseCharacter::GetBodyPartList(EBodyPart part, bool isFemale)
{
	FString Name = FString::Printf(TEXT("%s%s"), isFemale ? TEXT("Female") : TEXT("Male"), BodyPartNames[(int)part]);
	return SBodyParts ? SBodyParts -> FindRow<FSMeshAssetList>(*Name, nullptr) : nullptr;
}

void AFinalBaseCharacter::OnConstruction(const FTransform& Transform)
{
	UpdateBodyParts();
}









