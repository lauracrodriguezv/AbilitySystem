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
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//----------------------------------------------------------------------------------------------------------------------
void AAS_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

