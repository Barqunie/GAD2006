// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "Net/UnrealNetwork.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "NetBaseCharacter.generated.h"

UENUM(BlueprintType)
enum class EBodyPart : uint8 {
	BP_Face = 0,
	BP_Hair = 1,
	BP_Chest = 2,
	BP_Hands = 3,
	BP_Legs = 4,
	BP_Beard = 5,
	BP_Eyebrows = 6,
	BP_COUNT = 7,
};

USTRUCT(BlueprintType)
struct FSMeshAssetList : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<USkeletalMesh*> ListSkeletal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMesh*> ListStatic;
};

USTRUCT(BlueprintType)
struct FSBodyPartSelection
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> Indices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isFemale;

	FSBodyPartSelection()
	{
		isFemale = false;
		Indices.Init(0, (int32)EBodyPart::BP_COUNT);
	}
};

USTRUCT(BlueprintType)
struct FSPlayerInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Nickname;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSBodyPartSelection BodyParts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Ready;

	FSPlayerInfo()
	{
		Ready = false;
	}
};

UCLASS()
class ANetBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANetBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ChangeBodyPart(EBodyPart index, int value, bool DirectSet);

	UFUNCTION(BlueprintCallable)
	void ChangeGender(bool isFemale);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_PlayerInfoChanged)
	FSBodyPartSelection PartSelection;

	UFUNCTION(Server, Reliable)
	void SubmitPlayerInfoToServer(FSPlayerInfo Info);

	UFUNCTION()
	void OnRep_PlayerInfoChanged();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UPROPERTY()
	USkeletalMeshComponent* PartFace;

	UPROPERTY()
	UStaticMeshComponent* PartHair;

	UPROPERTY()
	UStaticMeshComponent* PartBeard;

	UPROPERTY()
	USkeletalMeshComponent* PartChest;

	UPROPERTY()
	USkeletalMeshComponent* PartHands;

	UPROPERTY()
	USkeletalMeshComponent* PartLegs;

	UPROPERTY()
	USkeletalMeshComponent* PartEyes;

	UPROPERTY()
	USkeletalMeshComponent* Eyebrows;

	UPROPERTY()
	UStaticMeshComponent* PartEyebrows;

	static FSMeshAssetList* GetBodyPartList(EBodyPart part, bool isFemale);

	void UpdateBodyParts();
};