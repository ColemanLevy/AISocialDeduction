// Fill out your copyright notice in the Description page of Project Settings.


#include "DecideToMeander.h"
#include "AIDeductionGameMode.h"

// Function used by Innocent Crewmates to determine if they should meander instead of performing a task.
bool UDecideToMeander::CalculateRawConditionValue(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) const
{
	return FMath::RandRange(0, 99) < Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode())->_chanceToMeander;
}