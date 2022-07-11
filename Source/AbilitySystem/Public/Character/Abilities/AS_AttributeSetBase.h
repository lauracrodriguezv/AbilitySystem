// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AS_AttributeSetBase.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAS_AttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:

	UAS_AttributeSetBase();
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AtributteSetBase")
	FGameplayAttributeData Health;
};
