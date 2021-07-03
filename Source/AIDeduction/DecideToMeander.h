// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "DecideToMeander.generated.h"

/**
 * 
 */
UCLASS()
class AIDEDUCTION_API UDecideToMeander : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	// Function used by Innocent Crewmates to determine if they should meander instead of performing a task.
	bool CalculateRawConditionValue(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) const override;
};
