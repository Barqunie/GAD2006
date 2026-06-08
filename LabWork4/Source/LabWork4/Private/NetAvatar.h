// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NetBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NetAvatar.generated.h"

/**
 * 
 */
UCLASS()
class ANetAvatar : public ANetBaseCharacter
{
	GENERATED_BODY()
	
public:

	ANetAvatar();

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;


	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float WalkSpeed = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RunSpeed = 600.f;

	UPROPERTY(ReplicatedUsing = OnRep_IsRunning, BlueprintReadOnly, Category = "Movement")
	bool bIsRunning = false;

	UFUNCTION()
	void OnRep_IsRunning();

	UFUNCTION(Server, Reliable)
	void ServerSetRunning(bool bNewRunning);

	void StartRunning();
	void StopRunning();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);
};
