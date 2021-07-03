// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "DecideToKill.generated.h"

/**
 * 
 */
UCLASS()
class AIDEDUCTION_API UDecideToKill : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	/// <summary>
	/// Function that is called whenever a killer decides to kill. Chooses a target for the killer to chase down from all of the Crewmates in sight.
	/// </summary>
	bool CalculateRawConditionValue(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) const override;
};
