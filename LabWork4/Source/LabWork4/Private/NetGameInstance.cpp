// Fill out your copyright notice in the Description page of Project Settings.


#include "NetGameInstance.h"

void UNetGameInstance::Host(FString MapName, FSPlayerInfo Info)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Hosting Game"), *MapName));
	PlayerInfo = Info;
	GWorld->ServerTravel(FString::Printf(TEXT("/Game/Maps/%s?listen"), *MapName));
}

void UNetGameInstance::Join(FString Address, FSPlayerInfo Info)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Joining Game at %s"), *Address));
	PlayerInfo = Info;
	GWorld->GetFirstPlayerController()->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
