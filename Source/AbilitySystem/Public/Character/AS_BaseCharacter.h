// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AS_BaseCharacter.generated.h"

UCLASS()
class ABILITYSYSTEM_API AAS_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AAS_BaseCharacter();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
