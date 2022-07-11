// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "AS_BaseCharacter.generated.h"

class UAS_AttributeSetBase;

UCLASS()
class ABILITYSYSTEM_API AAS_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

protected:

	//------------------------------------------------------------------------------------------------------------------
	// Components

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "CharacterBase")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "CharacterBase")
	TObjectPtr<UAS_AttributeSetBase> AttributeSetBaseComponent;
	
	//------------------------------------------------------------------------------------------------------------------
	// Animation and effects
	
	/** anim instance reference */
	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	TObjectPtr<UAnimInstance> AnimInstance;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	TObjectPtr<UAnimMontage> AttackMontage;

	//------------------------------------------------------------------------------------------------------------------
	// Abilities

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Ability")
	TSubclassOf<UGameplayAbility> Melee_GameplayAbility;
	
public:

	AAS_BaseCharacter();

protected:

	virtual void BeginPlay() override;

	//------------------------------------------------------------------------------------------------------------------
	// Input handlers

	virtual void StartMeleeAttack();

public:	

	virtual void Tick(float DeltaTime) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category="CharacterBase")
	void AcquireAbility(const TSubclassOf<UGameplayAbility> AbilityToAcquire) const;
};
