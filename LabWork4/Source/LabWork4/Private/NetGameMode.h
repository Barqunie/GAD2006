// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TimerManager.h"
#include "NetGameInstance.h"
#include "NetAvatar.h"
#include "NetGameMode.generated.h"

class ANetPlayerState;

/**
 *
 */
UCLASS()
class ANetGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANetGameMode();

	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	UFUNCTION(BlueprintCallable)
	void AvatarsOverlapped(ANetAvatar* AvatarA, ANetAvatar* AvatarB);

	UFUNCTION(BlueprintCallable)
	void EndGame();

	// Assignment swap logic
	// If a Red player dies, call this with that Red player's PlayerIndex.
	// If Blue wins by timeout, the latest dead Red player will be preferred as the next Blue.
	// If no dead Red player exists, a random alive Red player will be picked.
	UFUNCTION(BlueprintCallable)
	void RegisterDeadRedPlayer(int32 DeadPlayerIndex);

protected:
	virtual void BeginPlay() override;

private:
	int32 TotalPlayersCount = 0;
	int32 TotalGames = 0;
	int32 PlayerStartIndex = 0;

	TArray<APlayerController*> AllPlayers;

	FTimerHandle BlueWinTimerHandle;

	EPlayerTeam LastWinningTeam = EPlayerTeam::TEAM_Unknown;
	int32 LastWinningPlayerIndex = -1;

	// Used when Blue wins by timeout.
	// We pick the Red player before results are changed, then swap in EndGame.
	int32 BlueWinSwapTargetIndex = -1;

	// Latest dead Red player.
	// Blue timeout swap uses this first if it is valid.
	int32 LastDeadRedPlayerIndex = -1;

	AActor* GetPlayerStart(FString Name, int32 Index);
	AActor* AssignTeamAndPlayerStart(AController* Player);

	void StartBlueWinTimer();
	void BlueTeamWinsByTimeout();
	void FinishRound(EPlayerTeam WinningTeam, int32 WinningPlayerIndex = -1);

	ANetPlayerState* GetBluePlayerState();
	ANetPlayerState* GetPlayerStateByIndexSafe(int32 PlayerIndex);
	ANetPlayerState* PickRedPlayerForSwap();

	void SwapBlueWithRedForNextRound();
};