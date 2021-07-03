// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CheckIfDoneWithTasks.generated.h"

/**
 * 
 */
UCLASS()
class AIDEDUCTION_API UCheckIfDoneWithTasks : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	// Checks if the crewmate in question has completed all their tasks
	bool CalculateRawConditionValue(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) const override;
};
