// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "StartCrewmateTask.generated.h"

/**
 * 
 */
UCLASS()
class AIDEDUCTION_API UStartCrewmateTask : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	/// <summary>
	/// Function which informs the Crewmate they've started a new task.
	/// </summary>
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) override;
};
