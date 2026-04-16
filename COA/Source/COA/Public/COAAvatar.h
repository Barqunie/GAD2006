// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "COABaseCharacter.h"
#include "COAAvatar.generated.h"

UCLASS()
class COA_API ACOAAvatar : public ACOABaseCharacter
{
    GENERATED_BODY()
public:
    ACOAAvatar();

protected:
    virtual void BeginPlay() override;

private:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void Turn(float Value);
    void LookUp(float Value);
    void RunPressed();
    void RunReleased();
    void UpdateStamina();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* mSpringArm;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* mCamera;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA", meta = (AllowPrivateAccess = "true"))
    float RunSpeed = 600.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA", meta = (AllowPrivateAccess = "true"))
    float Stamina = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA", meta = (AllowPrivateAccess = "true"))
    float MaxStamina = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA", meta = (AllowPrivateAccess = "true"))
    float StaminaGainRate = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA", meta = (AllowPrivateAccess = "true"))
    float StaminaDrainRate = 20.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "COA", meta = (AllowPrivateAccess = "true"))
    bool bStaminaDrained = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "COA", meta = (AllowPrivateAccess = "true"))
    bool bRunning = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA", meta = (AllowPrivateAccess = "true"))
    float StaminaTickInterval = 0.1f;

    FTimerHandle StaminaTimerHandle;
};