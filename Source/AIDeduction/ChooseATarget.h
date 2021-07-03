// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseATarget.generated.h"

/**
 * 
 */
UCLASS()
class AIDEDUCTION_API UChooseATarget : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	// Selects an Innocent crewmate to be the target of a kill
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) override;
};
