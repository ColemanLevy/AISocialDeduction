// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PerformKill.generated.h"

/**
 * 
 */
UCLASS()
class AIDEDUCTION_API UPerformKill : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	/// <summary>
	/// Function where a Killer attempts to kill an Innocent target.
	/// </summary>
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) override;
};
