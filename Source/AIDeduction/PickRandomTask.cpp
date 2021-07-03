// Fill out your copyright notice in the Description page of Project Settings.


#include "PickRandomTask.h"
#include "CrewMateController.h"

#include "BehaviorTree/BlackboardComponent.h"

// Grabs the next task for this Crewmate to perform from their list of randomly assigned tasks.
EBTNodeResult::Type UPickRandomTask::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory)
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());
	
	if (crewmateController)
	{
		UBlackboardComponent* blackboardComp = crewmateController->GetBlackboardComp();

		blackboardComp->SetValueAsObject("LocationToGo", crewmateController->GetNextUnfinishedTask());

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}