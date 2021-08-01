// Fill out your copyright notice in the Description page of Project Settings.


#include "DecideToDoTask.h"
#include "AIDeductionGameMode.h"

// Function used by Innocent Crewmates to determine if they should perform a task.
bool UDecideToDoTask::CalculateRawConditionValue(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) const
{
	return FMath::RandRange(0, 99) < Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode())->_chanceToDoTask;
}