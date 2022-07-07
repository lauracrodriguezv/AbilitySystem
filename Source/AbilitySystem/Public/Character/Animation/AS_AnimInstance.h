// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AS_AnimInstance.generated.h"

class AAS_BaseCharacter;
class AAS_PlayerCharacter;
/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAS_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UAS_AnimInstance();

protected:

	UPROPERTY(BlueprintReadOnly, Category="Character")
	TObjectPtr<AAS_BaseCharacter> CharacterOwner;
	
	UPROPERTY(BlueprintReadOnly, Category="Character")
	TObjectPtr<AAS_PlayerCharacter> PlayerOwner;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FVector Velocity;
	
	UPROPERTY(BlueprintReadOnly, Category="Movement")
	uint8 bIsAccelerating : 1;
	
	UPROPERTY(BlueprintReadOnly, Category="Movement")
	uint8 bIsInAir : 1;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	uint8 bIsCrouched : 1;

public:
	
	virtual void NativeInitializeAnimation() override;

	void InitializeReferences();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void UpdateCharacterVariables();
};
