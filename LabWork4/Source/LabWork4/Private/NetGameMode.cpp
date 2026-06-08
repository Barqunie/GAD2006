// Fill out your copyright notice in the Description page of Project Settings.

#include "NetGameMode.h"
#include "NetBaseCharacter.h"
#include "NetGameState.h"
#include "NetPlayerState.h"
#include "NetAvatar.h"

#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"
#include "Components/CapsuleComponent.h"
#include "TimerManager.h"

ANetGameMode::ANetGameMode()
{
	DefaultPawnClass = ANetBaseCharacter::StaticClass();
	PlayerStateClass = ANetPlayerState::StaticClass();
	GameStateClass = ANetGameState::StaticClass();
}

void ANetGameMode::BeginPlay()
{
	Super::BeginPlay();

	StartBlueWinTimer();
}

void ANetGameMode::StartBlueWinTimer()
{
	if (!GetWorld())
	{
		return;
	}

	GetWorld()->GetTimerManager().ClearTimer(BlueWinTimerHandle);

	GetWorld()->GetTimerManager().SetTimer(
		BlueWinTimerHandle,
		this,
		&ANetGameMode::BlueTeamWinsByTimeout,
		30.0f,
		false
	);
}

void ANetGameMode::BlueTeamWinsByTimeout()
{
	ANetGameState* GState = GetGameState<ANetGameState>();

	if (GState == nullptr || GState->WinningPlayer >= 0)
	{
		return;
	}

	// Assignment swap logic:
	// If Blue survives until the timeout, Blue swaps with a Red player.
	// My rule:
	// 1) Prefer the latest dead Red player.
	// 2) If there is no latest dead Red player, randomly pick from Red players who have not lost/died yet.
	// 3) If no alive Red is found, randomly pick any Red player.
	ANetPlayerState* PickedRed = PickRedPlayerForSwap();
	BlueWinSwapTargetIndex = PickedRed ? PickedRed->PlayerIndex : -1;

	FinishRound(EPlayerTeam::TEAM_Blue);
}

AActor* ANetGameMode::GetPlayerStart(FString Name, int Index)
{
	FName PSName;

	if (Index < 0)
	{
		PSName = *Name;
	}
	else
	{
		PSName = *FString::Printf(TEXT("%s%d"), *Name, Index % 4);
	}

	for (TActorIterator<APlayerStart> It(GetWorld()); It; ++It)
	{
		APlayerStart* PS = Cast<APlayerStart>(*It);

		if (PS && PS->PlayerStartTag == PSName)
		{
			return *It;
		}
	}

	return nullptr;
}

AActor* ANetGameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	AActor* Start = AssignTeamAndPlayerStart(Player);
	return Start ? Start : Super::ChoosePlayerStart_Implementation(Player);
}

AActor* ANetGameMode::AssignTeamAndPlayerStart(AController* Player)
{
	if (Player == nullptr)
	{
		return nullptr;
	}

	AActor* Start = nullptr;

	ANetPlayerState* State = Player->GetPlayerState<ANetPlayerState>();
	APlayerController* PC = Cast<APlayerController>(Player);

	if (State)
	{
		// First time this player enters the match, assign player index and initial team.
		// First player becomes Blue, every other player starts as Red.
		if (PC && !AllPlayers.Contains(PC))
		{
			State->PlayerIndex = TotalPlayersCount;

			if (TotalPlayersCount == 0)
			{
				State->TeamID = EPlayerTeam::TEAM_Blue;
			}
			else
			{
				State->TeamID = EPlayerTeam::TEAM_Red;
			}

			State->Data.TeamID = State->TeamID;

			TotalPlayersCount++;
			AllPlayers.Add(PC);
		}

		if (State->TeamID == EPlayerTeam::TEAM_Blue)
		{
			Start = GetPlayerStart(TEXT("Blue"), -1);
		}
		else if (State->TeamID == EPlayerTeam::TEAM_Red)
		{
			Start = GetPlayerStart(TEXT("Red"), PlayerStartIndex++);
		}
	}

	return Start;
}

void ANetGameMode::AvatarsOverlapped(ANetAvatar* AvatarA, ANetAvatar* AvatarB)
{
	if (!HasAuthority())
	{
		return;
	}

	if (AvatarA == nullptr || AvatarB == nullptr)
	{
		return;
	}

	ANetGameState* GState = GetGameState<ANetGameState>();

	if (GState == nullptr || GState->WinningPlayer >= 0)
	{
		return;
	}

	ANetPlayerState* StateA = AvatarA->GetPlayerState<ANetPlayerState>();
	ANetPlayerState* StateB = AvatarB->GetPlayerState<ANetPlayerState>();

	if (StateA == nullptr || StateB == nullptr)
	{
		return;
	}

	if (StateA->TeamID == StateB->TeamID)
	{
		return;
	}

	int32 WinningPlayerIndex = -1;

	if (StateA->TeamID == EPlayerTeam::TEAM_Red)
	{
		WinningPlayerIndex = StateA->PlayerIndex;
	}
	else if (StateB->TeamID == EPlayerTeam::TEAM_Red)
	{
		WinningPlayerIndex = StateB->PlayerIndex;
	}

	if (AvatarA->GetCapsuleComponent())
	{
		AvatarA->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	}

	if (AvatarB->GetCapsuleComponent())
	{
		AvatarB->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	}

	// Red caught Blue before timeout.
	// The catching Red player becomes the next Blue player.
	FinishRound(EPlayerTeam::TEAM_Red, WinningPlayerIndex);
}

void ANetGameMode::FinishRound(EPlayerTeam WinningTeam, int32 WinningPlayerIndex)
{
	ANetGameState* GState = GetGameState<ANetGameState>();

	if (GState == nullptr || GState->WinningPlayer >= 0)
	{
		return;
	}

	GetWorld()->GetTimerManager().ClearTimer(BlueWinTimerHandle);

	LastWinningTeam = WinningTeam;
	LastWinningPlayerIndex = WinningPlayerIndex;

	for (APlayerController* Player : AllPlayers)
	{
		if (Player == nullptr)
		{
			continue;
		}

		ANetPlayerState* State = Player->GetPlayerState<ANetPlayerState>();

		if (State == nullptr)
		{
			continue;
		}

		if (State->TeamID == WinningTeam)
		{
			State->Result = EGameResults::RESULT_Won;

			if (GState->WinningPlayer < 0)
			{
				GState->WinningPlayer = State->PlayerIndex;
			}
		}
		else
		{
			State->Result = EGameResults::RESULT_Lost;
		}
	}

	if (WinningPlayerIndex >= 0)
	{
		GState->WinningPlayer = WinningPlayerIndex;
	}

	GState->OnVictory();

	FTimerHandle EndGameTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		EndGameTimerHandle,
		this,
		&ANetGameMode::EndGame,
		2.5f,
		false
	);
}

ANetPlayerState* ANetGameMode::GetBluePlayerState()
{
	for (APlayerController* Player : AllPlayers)
	{
		if (Player == nullptr)
		{
			continue;
		}

		ANetPlayerState* State = Player->GetPlayerState<ANetPlayerState>();

		if (State && State->TeamID == EPlayerTeam::TEAM_Blue)
		{
			return State;
		}
	}

	return nullptr;
}

ANetPlayerState* ANetGameMode::GetPlayerStateByIndexSafe(int32 PlayerIndex)
{
	for (APlayerController* Player : AllPlayers)
	{
		if (Player == nullptr)
		{
			continue;
		}

		ANetPlayerState* State = Player->GetPlayerState<ANetPlayerState>();

		if (State && State->PlayerIndex == PlayerIndex)
		{
			return State;
		}
	}

	return nullptr;
}

void ANetGameMode::RegisterDeadRedPlayer(int32 DeadPlayerIndex)
{
	ANetPlayerState* DeadState = GetPlayerStateByIndexSafe(DeadPlayerIndex);

	if (DeadState && DeadState->TeamID == EPlayerTeam::TEAM_Red)
	{
		LastDeadRedPlayerIndex = DeadPlayerIndex;
	}
}

ANetPlayerState* ANetGameMode::PickRedPlayerForSwap()
{
	// logic:
	// First, prefer the latest dead Red player.
	// If there is no valid latest dead Red player, choose randomly among alive Red players.
	// If there are no alive Red players, fallback to a random Red player.

	ANetPlayerState* LastDeadRed = GetPlayerStateByIndexSafe(LastDeadRedPlayerIndex);

	if (LastDeadRed && LastDeadRed->TeamID == EPlayerTeam::TEAM_Red)
	{
		return LastDeadRed;
	}

	TArray<ANetPlayerState*> AliveReds;
	TArray<ANetPlayerState*> AnyReds;

	for (APlayerController* Player : AllPlayers)
	{
		if (Player == nullptr)
		{
			continue;
		}

		ANetPlayerState* State = Player->GetPlayerState<ANetPlayerState>();

		if (State && State->TeamID == EPlayerTeam::TEAM_Red)
		{
			AnyReds.Add(State);

			if (State->Result != EGameResults::RESULT_Lost)
			{
				AliveReds.Add(State);
			}
		}
	}

	if (AliveReds.Num() > 0)
	{
		const int32 RandomIndex = FMath::RandRange(0, AliveReds.Num() - 1);
		return AliveReds[RandomIndex];
	}

	if (AnyReds.Num() > 0)
	{
		const int32 RandomIndex = FMath::RandRange(0, AnyReds.Num() - 1);
		return AnyReds[RandomIndex];
	}

	return nullptr;
}

void ANetGameMode::SwapBlueWithRedForNextRound()
{
	ANetPlayerState* OldBlueState = GetBluePlayerState();
	ANetPlayerState* NewBlueState = nullptr;

	if (LastWinningTeam == EPlayerTeam::TEAM_Red && LastWinningPlayerIndex >= 0)
	{
		NewBlueState = GetPlayerStateByIndexSafe(LastWinningPlayerIndex);
	}
	else if (LastWinningTeam == EPlayerTeam::TEAM_Blue && BlueWinSwapTargetIndex >= 0)
	{
		NewBlueState = GetPlayerStateByIndexSafe(BlueWinSwapTargetIndex);
	}

	if (NewBlueState == nullptr || NewBlueState->TeamID != EPlayerTeam::TEAM_Red)
	{
		NewBlueState = PickRedPlayerForSwap();
	}

	if (OldBlueState == nullptr || NewBlueState == nullptr || OldBlueState == NewBlueState)
	{
		return;
	}

	OldBlueState->TeamID = EPlayerTeam::TEAM_Red;
	OldBlueState->Data.TeamID = EPlayerTeam::TEAM_Red;

	NewBlueState->TeamID = EPlayerTeam::TEAM_Blue;
	NewBlueState->Data.TeamID = EPlayerTeam::TEAM_Blue;
}

void ANetGameMode::EndGame()
{
	PlayerStartIndex = 0;
	TotalGames++;

	SwapBlueWithRedForNextRound();

	ANetGameState* GState = GetGameState<ANetGameState>();

	if (GState)
	{
		GState->WinningPlayer = -1;
	}

	for (APlayerController* Player : AllPlayers)
	{
		if (Player == nullptr)
		{
			continue;
		}

		ANetPlayerState* State = Player->GetPlayerState<ANetPlayerState>();

		if (State)
		{
			State->Result = EGameResults::RESULT_Undefined;
			State->Data.TeamID = State->TeamID;
		}

		APawn* Pawn = Player->GetPawn();

		if (Pawn)
		{
			Player->UnPossess();
			Pawn->Destroy();
		}

		Player->StartSpot.Reset();
		RestartPlayer(Player);
	}

	if (GState)
	{
		GState->TriggerRestart();
	}

	LastWinningTeam = EPlayerTeam::TEAM_Unknown;
	LastWinningPlayerIndex = -1;
	BlueWinSwapTargetIndex = -1;
	LastDeadRedPlayerIndex = -1;

	StartBlueWinTimer();
}