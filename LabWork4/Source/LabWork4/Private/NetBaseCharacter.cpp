// Fill out your copyright notice in the Description page of Project Settings.

#include "NetBaseCharacter.h"
#include "NetGameInstance.h"
#include "NetPlayerState.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerManager.h"
#include "NetGameState.h"
#include "Engine/World.h"

static UDataTable* SBodyParts = nullptr;

static const TArray<FString> BodyPartNames =
{
	TEXT("Face"),
	TEXT("Hair"),
	TEXT("Chest"),
	TEXT("Hands"),
	TEXT("Legs"),
	TEXT("Beard"),
	TEXT("Eyebrows")
};

// Sets default values
ANetBaseCharacter::ANetBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	for (int32 i = 0; i < (int32)EBodyPart::BP_COUNT; i++)
	{
		BodyPartIndices[i] = 0;
	}

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

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_Eyes(
		TEXT("SkeletalMesh'/Game/StylizedModularChar/Meshes/SK_Eyes.SK_Eyes'")
	);

	PartEyes = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Eyes"));
	PartEyes->SetupAttachment(GetMesh());

	if (SK_Eyes.Succeeded())
	{
		PartEyes->SetSkeletalMesh(SK_Eyes.Object);
	}

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_BodyParts(
		TEXT("DataTable'/Game/Blueprints/DT_BodyParts.DT_BodyParts'")
	);

	if (DT_BodyParts.Succeeded())
	{
		SBodyParts = DT_BodyParts.Object;
	}
}

// Called when the game starts or when spawned
void ANetBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		return;
	}

	SetActorHiddenInGame(true);
	CheckPlayerState();
}

// Called every frame
void ANetBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANetBaseCharacter::SubmitPlayerInfoToServer_Implementation(FSPlayerInfo Info)
{
	ANetPlayerState* State = GetPlayerState<ANetPlayerState>();

	if (State == nullptr)
	{
		return;
	}

	State->Data.Nickname = Info.Nickname;
	State->Data.CustomizationData = Info.CustomizationData;
	State->Data.TeamID = State->TeamID;
	PlayerInfoReceived = true;


	CheckPlayerInfo();
}

void ANetBaseCharacter::ChangeBodyPart(EBodyPart index, int value, bool DirectSet)
{
	const int32 BodyPartIndex = (int32)index;

	if (BodyPartIndex < 0 || BodyPartIndex >= (int32)EBodyPart::BP_COUNT)
	{
		return;
	}

	if (index == EBodyPart::BP_BodyType)
	{
		BodyPartIndices[BodyPartIndex] = DirectSet ? value : BodyPartIndices[BodyPartIndex] + value;
		BodyPartIndices[BodyPartIndex] = BodyPartIndices[BodyPartIndex] > 0 ? 1 : 0;

		if (BodyPartIndices[BodyPartIndex] == 1)
		{
			BodyPartIndices[(int32)EBodyPart::BP_Beard] = 0;

			if (PartBeard)
			{
				PartBeard->SetStaticMesh(nullptr);
			}
		}

		UpdateBodyParts();
		return;
	}

	const bool bIsFemale = BodyPartIndices[(int32)EBodyPart::BP_BodyType] != 0;

	if (index == EBodyPart::BP_Beard && bIsFemale)
	{
		BodyPartIndices[(int32)EBodyPart::BP_Beard] = 0;

		if (PartBeard)
		{
			PartBeard->SetStaticMesh(nullptr);
		}

		return;
	}

	FSMeshAssetList* List = GetBodyPartList(index, bIsFemale);
	if (List == nullptr) return;

	int32 Num = List->ListSkeletal.Num() + List->ListStatic.Num();
	if (Num <= 0) return;

	int32 CurrentIndex = BodyPartIndices[BodyPartIndex];

	if (DirectSet)
	{
		CurrentIndex = value;
	}
	else
	{
		CurrentIndex += value;
	}

	CurrentIndex = ((CurrentIndex % Num) + Num) % Num;

	BodyPartIndices[BodyPartIndex] = CurrentIndex;

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

	default:
		break;
	}
}

void ANetBaseCharacter::ChangeGender(bool _isFemale)
{
	BodyPartIndices[(int32)EBodyPart::BP_BodyType] = _isFemale ? 1 : 0;

	if (_isFemale)
	{
		BodyPartIndices[(int32)EBodyPart::BP_Beard] = 0;

		if (PartBeard)
		{
			PartBeard->SetStaticMesh(nullptr);
		}
	}

	UpdateBodyParts();
}

void ANetBaseCharacter::CheckPlayerState()
{
	ANetPlayerState* State = GetPlayerState<ANetPlayerState>();

	if (State == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("State == nullptr"));

		GetWorld()->GetTimerManager().SetTimer(
			ClientDataCheckTimer,
			this,
			&ANetBaseCharacter::CheckPlayerState,
			0.25f,
			false
		);
	}
	else
	{
		if (IsLocallyControlled())
		{
			UNetGameInstance* Instance = Cast<UNetGameInstance>(GetWorld()->GetGameInstance());

			if (Instance)
			{
				//Instance->PlayerInfo.CustomizationData = GetCustomizationData(); //burasi kiyafet gondermede sorundu 
				SubmitPlayerInfoToServer(Instance->PlayerInfo);
			}
		}

		CheckPlayerInfo();
	}
}

void ANetBaseCharacter::CheckPlayerInfo()
{
	ANetPlayerState* State = GetPlayerState<ANetPlayerState>();

	if (State && !State->Data.CustomizationData.IsEmpty()) //Client Tarafi sorunluydu if kontrolu degistirdim
	{
		ParseCustomizationData(State->Data.CustomizationData);
		UpdateBodyParts();
		OnPlayerInfoChanged();
		SetActorHiddenInGame(false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("State Not Received!"));

		GetWorld()->GetTimerManager().SetTimer(
			ClientDataCheckTimer,
			this,
			&ANetBaseCharacter::CheckPlayerInfo,
			0.25f,
			false
		);
	}
}

FString ANetBaseCharacter::GetCustomizationData()
{
	FString Data;

	for (int32 i = 0; i < (int32)EBodyPart::BP_COUNT; i++)
	{
		Data += FString::FromInt(BodyPartIndices[i]);

		if (i < ((int32)EBodyPart::BP_COUNT) - 1)
		{
			Data += TEXT(",");
		}
	}

	return Data;
}

void ANetBaseCharacter::ParseCustomizationData(FString BodyPartData)
{
	TArray<FString> ArrayData;
	BodyPartData.ParseIntoArray(ArrayData, TEXT(","), true);

	for (int32 i = 0; i < (int32)EBodyPart::BP_COUNT; i++)
	{
		if (ArrayData.IsValidIndex(i))
		{
			BodyPartIndices[i] = FCString::Atoi(*ArrayData[i]);
		}
		else
		{
			BodyPartIndices[i] = 0;
		}
	}
}

void ANetBaseCharacter::UpdateBodyParts()
{
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

	if (part == EBodyPart::BP_BodyType)
	{
		return nullptr;
	}

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

	UpdateBodyParts();
}

// Called to bind functionality to input
void ANetBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}