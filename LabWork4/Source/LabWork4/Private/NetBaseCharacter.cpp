// Fill out your copyright notice in the Description page of Project Settings.

#include "NetBaseCharacter.h"
#include "NetGameInstance.h"
#include "UObject/ConstructorHelpers.h"

static UDataTable* SBodyParts = nullptr;

static const TArray<FString> BodyPartNames = {
	TEXT("Face"),
	TEXT("Hair"),
	TEXT("Chest"),
	TEXT("Hands"),
	TEXT("Legs"),
	TEXT("Beard"),
	TEXT("Eyebrows")
};

static void EnsureBodyPartIndices(FSBodyPartSelection& Selection)
{
	const int32 Count = (int32)EBodyPart::BP_COUNT;

	if (Selection.Indices.Num() != Count)
	{
		Selection.Indices.SetNumZeroed(Count);
	}
}

// Sets default values
ANetBaseCharacter::ANetBaseCharacter()
{
	// Set this character to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PartFace = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Face"));
	PartFace->SetupAttachment(GetMesh());
	PartFace->SetLeaderPoseComponent(GetMesh());

	PartHands = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hands"));
	PartHands->SetupAttachment(GetMesh());
	PartHands->SetLeaderPoseComponent(GetMesh());

	PartLegs = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Legs"));
	PartLegs->SetupAttachment(GetMesh());
	PartLegs->SetLeaderPoseComponent(GetMesh());

	PartHair = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hair"));
	PartHair->SetupAttachment(PartFace, FName("headSocket"));

	PartBeard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Beard"));
	PartBeard->SetupAttachment(PartFace, FName("headSocket"));

	PartEyebrows = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Eyebrows"));
	PartEyebrows->SetupAttachment(PartFace, FName("headSocket"));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_Eyes(TEXT("SkeletalMesh'/Game/StylizedModularChar/Meshes/SK_Eyes.SK_Eyes'"));

	PartEyes = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Eyes"));
	PartEyes->SetupAttachment(GetMesh());

	if (SK_Eyes.Succeeded())
	{
		PartEyes->SetSkeletalMesh(SK_Eyes.Object);
	}

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_BodyParts(TEXT("DataTable'/Game/Blueprints/DT_BodyParts.DT_BodyParts'"));

	if (DT_BodyParts.Succeeded())
	{
		SBodyParts = DT_BodyParts.Object;
	}

	EnsureBodyPartIndices(PartSelection);
}

// Called when the game starts or when spawned
void ANetBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	EnsureBodyPartIndices(PartSelection);

	if (IsLocallyControlled())
	{
		UNetGameInstance* Instance = Cast<UNetGameInstance>(GWorld->GetGameInstance());
		if (Instance && Instance->PlayerInfo.Ready)
		{
			SubmitPlayerInfoToServer(Instance->PlayerInfo);
		}
	}
}

// Called every frame
void ANetBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANetBaseCharacter::ChangeBodyPart(EBodyPart index, int value, bool DirectSet)
{
	EnsureBodyPartIndices(PartSelection);

	const int32 BodyPartIndex = (int32)index;

	if (!PartSelection.Indices.IsValidIndex(BodyPartIndex))
	{
		return;
	}

	if (index == EBodyPart::BP_Beard && PartSelection.isFemale)
	{
		PartSelection.Indices[(int32)EBodyPart::BP_Beard] = 0;

		if (PartBeard)
		{
			PartBeard->SetStaticMesh(nullptr);
		}

		return;
	}

	FSMeshAssetList* List = GetBodyPartList(index, PartSelection.isFemale);
	if (List == nullptr) return;

	int Num = List->ListSkeletal.Num() + List->ListStatic.Num();

	if (Num <= 0) return;

	int CurrentIndex = PartSelection.Indices[BodyPartIndex];

	if (DirectSet)
	{
		CurrentIndex = value;
	}
	else
	{
		CurrentIndex += value;
	}

	CurrentIndex = ((CurrentIndex % Num) + Num) % Num;

	PartSelection.Indices[BodyPartIndex] = CurrentIndex;

	switch (index)
	{
	case EBodyPart::BP_Face:
		if (List->ListSkeletal.IsValidIndex(CurrentIndex))
		{
			PartFace->SetSkeletalMeshAsset(List->ListSkeletal[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Beard:
		if (List->ListStatic.IsValidIndex(CurrentIndex))
		{
			PartBeard->SetStaticMesh(List->ListStatic[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Chest:
		if (List->ListSkeletal.IsValidIndex(CurrentIndex))
		{
			GetMesh()->SetSkeletalMeshAsset(List->ListSkeletal[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Hair:
		if (List->ListStatic.IsValidIndex(CurrentIndex))
		{
			PartHair->SetStaticMesh(List->ListStatic[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Hands:
		if (List->ListSkeletal.IsValidIndex(CurrentIndex))
		{
			PartHands->SetSkeletalMeshAsset(List->ListSkeletal[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Legs:
		if (List->ListSkeletal.IsValidIndex(CurrentIndex))
		{
			PartLegs->SetSkeletalMeshAsset(List->ListSkeletal[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Eyebrows:
		if (List->ListStatic.IsValidIndex(CurrentIndex))
		{
			PartEyebrows->SetStaticMesh(List->ListStatic[CurrentIndex]);
		}
		break;
	}
}

void ANetBaseCharacter::ChangeGender(bool _isFemale)
{
	EnsureBodyPartIndices(PartSelection);

	PartSelection.isFemale = _isFemale;

	if (_isFemale)
	{
		PartSelection.Indices[(int32)EBodyPart::BP_Beard] = 0;

		if (PartBeard)
		{
			PartBeard->SetStaticMesh(nullptr);
		}
	}

	UpdateBodyParts();
}

void ANetBaseCharacter::SubmitPlayerInfoToServer_Implementation(FSPlayerInfo Info)
{
	PartSelection = Info.BodyParts;
	EnsureBodyPartIndices(PartSelection);

	if (HasAuthority())
	{
		OnRep_PlayerInfoChanged();
	}
}

void ANetBaseCharacter::OnRep_PlayerInfoChanged()
{
	EnsureBodyPartIndices(PartSelection);
	UpdateBodyParts();
}

void ANetBaseCharacter::UpdateBodyParts()
{
	EnsureBodyPartIndices(PartSelection);

	ChangeBodyPart(EBodyPart::BP_Face, 0, false);
	ChangeBodyPart(EBodyPart::BP_Beard, 0, false);
	ChangeBodyPart(EBodyPart::BP_Chest, 0, false);
	ChangeBodyPart(EBodyPart::BP_Hair, 0, false);
	ChangeBodyPart(EBodyPart::BP_Hands, 0, false);
	ChangeBodyPart(EBodyPart::BP_Legs, 0, false);
	ChangeBodyPart(EBodyPart::BP_Eyebrows, 0, false);
}

FSMeshAssetList* ANetBaseCharacter::GetBodyPartList(EBodyPart part, bool isFemale)
{
	const int32 BodyPartIndex = (int32)part;

	if (!BodyPartNames.IsValidIndex(BodyPartIndex))
	{
		return nullptr;
	}

	FString Name = FString::Printf(
		TEXT("%s%s"),
		isFemale ? TEXT("Female") : TEXT("Male"),
		*BodyPartNames[BodyPartIndex]
	);

	return SBodyParts ? SBodyParts->FindRow<FSMeshAssetList>(*Name, nullptr) : nullptr;
}

void ANetBaseCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	EnsureBodyPartIndices(PartSelection);
	UpdateBodyParts();
}

void ANetBaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ANetBaseCharacter, PartSelection);
}

// Called to bind functionality to input
void ANetBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}