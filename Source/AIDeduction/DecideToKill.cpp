// Fill out your copyright notice in the Description page of Project Settings.


#include "DecideToKill.h"
#include "AIDeductionGameMode.h"

// Function that is called whenever a killer decides to kill. Chooses a target for the killer to chase down from all of the Crewmates in sight.
bool UDecideToKill::CalculateRawConditionValue(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) const
{
	return FMath::RandRange(0, 99) < Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode())->_chanceToKill;
}