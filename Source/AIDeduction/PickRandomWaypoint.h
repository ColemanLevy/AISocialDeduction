// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PickRandomWaypoint.generated.h"

/**
 * Node for the crewmate's behavior tree which gets the crewmate a random waypoint to move to.
 */
UCLASS()
class AIDEDUCTION_API UPickRandomWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	// Grabs a random waypoint from the GameMode's list of available waypoints for the Crewmate to move to.
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) override;
};
