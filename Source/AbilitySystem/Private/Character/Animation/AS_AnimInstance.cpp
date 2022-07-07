// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Animation/AS_AnimInstance.h"

#include "Character/AS_BaseCharacter.h"
#include "Character/AS_PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

UAS_AnimInstance::UAS_AnimInstance()
{
}

//----------------------------------------------------------------------------------------------------------------------
void UAS_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	InitializeReferences();
}

//----------------------------------------------------------------------------------------------------------------------
void UAS_AnimInstance::InitializeReferences()
{
	CharacterOwner = Cast<AAS_BaseCharacter>(TryGetPawnOwner());
	PlayerOwner = Cast<AAS_PlayerCharacter>(TryGetPawnOwner());
}

//----------------------------------------------------------------------------------------------------------------------
void UAS_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	UpdateCharacterVariables();
}

//----------------------------------------------------------------------------------------------------------------------
void UAS_AnimInstance::UpdateCharacterVariables()
{
	if(IsValid(CharacterOwner))
	{
		Velocity = CharacterOwner->GetVelocity();
		Velocity.Z = 0.0f;
		Speed = Velocity.Size();

		if(IsValid(CharacterOwner->GetMesh()))
		{
			Velocity = UKismetMathLibrary::InverseTransformDirection(CharacterOwner->GetMesh()->GetComponentTransform(), Velocity);
		}

		bIsInAir = CharacterOwner->GetCharacterMovement()->IsFalling();
		bIsAccelerating = CharacterOwner->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.0f;
		bIsCrouched = CharacterOwner->GetCharacterMovement()->IsCrouching();
	}
}
