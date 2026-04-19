// Fill out your copyright notice in the Description page of Project Settings.


#include "TBPlayerController.h"


ATBPlayerController::ATBPlayerController()
{
	
}

void ATBPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	bEnableClickEvents = true;
	bShowMouseCursor = true;
	ClickEventKeys.Add(EKeys::RightMouseButton);
}

void ATBPlayerController::OnActorClicked(AActor* Actor, FKey key)
{

	if(GameManager)
	{
		GameManager->OnActorClicked(Actor, key);
	}
}

