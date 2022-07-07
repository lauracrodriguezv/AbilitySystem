// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AS_BaseCharacter.h"

//----------------------------------------------------------------------------------------------------------------------
AAS_BaseCharacter::AAS_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(GetMesh()))
	{
		AnimInstance = GetMesh()->GetAnimInstance();
	}
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_BaseCharacter::StartMeleeAttack()
{
	if(IsValid(AnimInstance) && IsValid(AttackMontage))
	{
		AnimInstance->Montage_Play(AttackMontage);
	}
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

