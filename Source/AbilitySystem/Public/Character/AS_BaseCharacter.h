// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AS_BaseCharacter.generated.h"

UCLASS()
class ABILITYSYSTEM_API AAS_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	//------------------------------------------------------------------------------------------------------------------
	// Animation and effects
	
	/** anim instance reference */
	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	TObjectPtr<UAnimInstance> AnimInstance;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	TObjectPtr<UAnimMontage> AttackMontage;
	
public:

	AAS_BaseCharacter();

protected:

	virtual void BeginPlay() override;

	//------------------------------------------------------------------------------------------------------------------
	// Input handlers

	virtual void StartMeleeAttack();

public:	

	virtual void Tick(float DeltaTime) override;
	
};
