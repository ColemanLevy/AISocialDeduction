// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CompleteCrewmateTask.generated.h"

/**
 * 
 */
UCLASS()
class AIDEDUCTION_API UCompleteCrewmateTask : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	// Indicates to the GameMode that a task has been completed
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) override;
};
