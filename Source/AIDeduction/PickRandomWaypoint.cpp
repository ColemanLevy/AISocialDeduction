// Fill out your copyright notice in the Description page of Project Settings.


#include "PickRandomWaypoint.h"
#include "AIDeductionGameMode.h"
#include "CrewMateController.h"
#include "Waypoint.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

// Gets random waypoint for the crewmate to move to
EBTNodeResult::Type UPickRandomWaypoint::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory)
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());

	if (crewmateController)
	{
		UBlackboardComponent* blackboardComp = crewmateController->GetBlackboardComp();

		// Gets the random waypoint from the game mode
		blackboardComp->SetValueAsObject("LocationToGo", crewmateController->_aiDeductionGameMode->GetRandomWaypoint());

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}