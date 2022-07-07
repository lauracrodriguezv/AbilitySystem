// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AS_PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

//----------------------------------------------------------------------------------------------------------------------
AAS_PlayerCharacter::AAS_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetMesh());
	SpringArmComponent->TargetArmLength = 600.f;
	SpringArmComponent->bUsePawnControlRotation = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;

	BaseTurnRate = 45.0f;
	BaseLookUpRate = 45.0f;
	bIsLookInverted = true;
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::MoveForward(float Value)
{
	if(IsValid(Controller)  && Value != 0.0f)
	{
		const FRotator YawRotation (0.0f, Controller->GetControlRotation().Yaw, 0.0f);
		const FVector Direction (FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Value);
	}
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::MoveRight(float Value)
{
	if(IsValid(Controller) && Value != 0.0f)
	{
		const FRotator YawRotation (0.0f, Controller->GetControlRotation().Yaw, 0.0f);
		const FVector Direction (FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, Value);
	}
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::TurnAtRate(float Value)
{
	AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::LookUpAtRate(float Value)
{
	AddControllerPitchInput(Value * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::AddControllerPitchInput(float Value)
{
	Super::AddControllerPitchInput(bIsLookInverted ? -Value : Value);
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::AddControllerYawInput(float Val)
{
	Super::AddControllerYawInput(Val);
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::Jump()
{
	Super::Jump();
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::StopJumping()
{
	Super::StopJumping();
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::StartCrouch()
{
	Crouch();
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::EndCrouch()
{
	UnCrouch();
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AAS_PlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAS_PlayerCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AAS_PlayerCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookingUp", this, &AAS_PlayerCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AAS_PlayerCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump",IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AAS_PlayerCharacter::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this,  &AAS_PlayerCharacter::EndCrouch);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AAS_PlayerCharacter::StartMeleeAttack);
}
