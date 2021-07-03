// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PickRandomTask.generated.h"

/**
 * 
 */
UCLASS()
class AIDEDUCTION_API UPickRandomTask : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	// Grabs the next task for this Crewmate to perform from their list of randomly assigned tasks.
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) override;
};
