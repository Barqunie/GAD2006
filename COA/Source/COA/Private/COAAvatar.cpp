#include "COAAvatar.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ACOAAvatar::ACOAAvatar()
{
    PrimaryActorTick.bCanEverTick = true;

    mSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    mSpringArm->SetupAttachment(RootComponent);
    mSpringArm->TargetArmLength = 300.0f;
    mSpringArm->bUsePawnControlRotation = true;

    mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    mCamera->SetupAttachment(mSpringArm, USpringArmComponent::SocketName);
    mCamera->bUsePawnControlRotation = false;
}

void ACOAAvatar::BeginPlay()
{
    Super::BeginPlay();

    GetWorldTimerManager().SetTimer(
        StaminaTimerHandle,
        this,
        &ACOAAvatar::UpdateStamina,
        StaminaTickInterval,
        true
    );
}

void ACOAAvatar::UpdateStamina()
{
    if (bRunning && !bStaminaDrained)
    {
        Stamina -= StaminaDrainRate * StaminaTickInterval;
        if (Stamina <= 0.0f)
        {
            Stamina = 0.0f;
            bStaminaDrained = true;
            GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
        }
    }
    else if (!bRunning)
    {
        Stamina = FMath::Min(MaxStamina, Stamina + StaminaGainRate * StaminaTickInterval);
        if (Stamina >= MaxStamina)
        {
            bStaminaDrained = false;
        }
    }
}

void ACOAAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("Turn", this, &ACOAAvatar::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &ACOAAvatar::LookUp);
    PlayerInputComponent->BindAxis("MoveForward", this, &ACOAAvatar::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ACOAAvatar::MoveRight);
    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ACOAAvatar::RunPressed);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &ACOAAvatar::RunReleased);
}

void ACOAAvatar::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void ACOAAvatar::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

void ACOAAvatar::MoveForward(float Value)
{
    if (!Controller) return;

    FRotator Rotation = Controller->GetControlRotation();
    FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
    FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    AddMovementInput(Direction, Value);
}

void ACOAAvatar::MoveRight(float Value)
{
    if (!Controller) return;

    FRotator Rotation = Controller->GetControlRotation();
    FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
    FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}

void ACOAAvatar::RunPressed()
{
    if (!bStaminaDrained)
    {
        bRunning = true;
        GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
    }
}

void ACOAAvatar::RunReleased()
{
    bRunning = false;
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}