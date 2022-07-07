// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AS_BaseCharacter.h"
#include "AS_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API AAS_PlayerCharacter : public AAS_BaseCharacter
{
	GENERATED_BODY()

protected:

	//------------------------------------------------------------------------------------------------------------------
	// Components
	
	/** Third person camera*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> CameraComponent;

	/** Camera boom */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	//------------------------------------------------------------------------------------------------------------------
	
	/** Camera can be inverted or normal */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aiming")
	uint8 bIsLookInverted : 1;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	float BaseTurnRate;

	/** Base lookup rate, in deg/sec. Other scaling may affect final lookup rate. */
	float BaseLookUpRate;
	
public:

	AAS_PlayerCharacter();
	
protected:

	//------------------------------------------------------------------------------------------------------------------
	// Input handlers
	
	void MoveForward(float Value);

	void MoveRight(float Value);

	/* Frame rate independent turn */
	void TurnAtRate(float Value);

	/* Frame rate independent lookup */
	void LookUpAtRate(float Value);

	virtual void AddControllerPitchInput(float Value) override;

	virtual void AddControllerYawInput(float Val) override;

	virtual void Jump() override;

	virtual void StopJumping() override;
	
	void StartCrouch();

	void EndCrouch();

public:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
