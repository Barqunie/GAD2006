// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGrid.h"
#include "Components/ChildActorComponent.h"

//Global ref to GameGrid
AGameGrid* AGameGrid::GameGrid = nullptr;

// Sets default values
AGameGrid::AGameGrid() :
NumRows(8),
NumCols(8)
{

	
 	
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	GameGrid = this;

}

AGameSlot* AGameGrid::GetSlot(FSGridPosition& Position)
{
	int GridIndex = Position.Row * NumCols + Position.Col;
	if(GridActors.IsValidIndex(GridIndex))
	{
		return Cast<AGameSlot>(GridActors[GridIndex]->GetChildActor());
	}
	return nullptr;
}

AGameSlot* AGameGrid::FindSlot(FSGridPosition Position)
{
	int GridIndex = Position.Row * GameGrid->NumCols + Position.Col;
	if(GameGrid->GridActors.IsValidIndex(GridIndex))
	{
		return Cast<AGameSlot>(GameGrid->GridActors[GridIndex]->GetChildActor());
	}	
	
	return nullptr;
}

void AGameGrid::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	for(auto Grid:GridActors)
	{
		Grid->DestroyComponent();
	}

	GridActors.Empty();

	if (!GridClass->IsValidLowLevel()) return;

	AGameSlot* Slot = GridClass->GetDefaultObject<AGameSlot>();

	if (Slot == nullptr) return;	

	FVector Extends = Slot->Box->GetUnscaledBoxExtent() * 2.f;

	for(int i=0; i<NumRows;i++)
	{
		for(int j=0; j<NumCols;j++)
		{
			FName GridName(FString::Printf(TEXT("Slot_%d_%d"), j, i));
			auto Grid = NewObject<UChildActorComponent>(this, UChildActorComponent::StaticClass(),GridName);
			Grid->RegisterComponent();
			Grid->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
			Grid->SetRelativeLocation(FVector(
				(NumRows - i - 1) * Extends.X - (NumRows * 0.5f - 0.5f) * Extends.X,
				j * Extends.Y - (NumCols * 0.5f - 0.5f) * Extends.Y, 0.f));

			GridActors.Add(Grid);

			Grid->SetChildActorClass(GridClass);
			AGameSlot* GameSlot = Cast<AGameSlot>(Grid->GetChildActor());	
			GameSlot->SetActorLabel(GridName.ToString());
		}
	}
}

void AGameGrid::Tick(float DeltaTime)
{
}

// Called when the game starts or when spawned
void AGameGrid::BeginPlay()
{
	Super::BeginPlay();

	int GridIndex = 0;

	for(int i=0; i<NumRows;i++)
	{
		for(int j=0; j<NumCols;j++)
		{
			AGameSlot* GameSlot = Cast<AGameSlot>(GridActors[GridIndex]->GetChildActor());
			GameSlot->GridPosition = FSGridPosition(j, i);
			GridIndex++;
		}
	}
	
}


