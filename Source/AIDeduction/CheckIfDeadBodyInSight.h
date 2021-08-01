// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CheckIfDeadBodyInSight.generated.h"

/**
 * 
 */
UCLASS()
class AIDEDUCTION_API UCheckIfDeadBodyInSight : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	// Checks if the crewmate in question has a dead body in their sights
	bool CalculateRawConditionValue(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) const override;
};
