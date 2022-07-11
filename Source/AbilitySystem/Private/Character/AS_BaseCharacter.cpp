// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AS_BaseCharacter.h"

#include "Character/Abilities/AS_AttributeSetBase.h"

//----------------------------------------------------------------------------------------------------------------------
AAS_BaseCharacter::AAS_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	AttributeSetBaseComponent = CreateDefaultSubobject<UAS_AttributeSetBase>(TEXT("AttributeSetBaseComponent"));
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(GetMesh()))
	{
		AnimInstance = GetMesh()->GetAnimInstance();
	}

	AcquireAbility(Melee_GameplayAbility);
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_BaseCharacter::StartMeleeAttack()
{
	if(IsValid(AbilitySystemComponent))
	{
		if(AbilitySystemComponent->TryActivateAbilityByClass(Melee_GameplayAbility))
		{
			if(IsValid(AnimInstance) && IsValid(AttackMontage))
			{
				AnimInstance->Montage_Play(AttackMontage);
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//----------------------------------------------------------------------------------------------------------------------
UAbilitySystemComponent* AAS_BaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_BaseCharacter::AcquireAbility(const TSubclassOf<UGameplayAbility> AbilityToAcquire) const
{
	if(IsValid(AbilitySystemComponent))
	{
		if(HasAuthority() && IsValid(AbilityToAcquire))
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityToAcquire));
		}
	
		AbilitySystemComponent->InitAbilityActorInfo(GetOwner(), GetOwner());
	}
}