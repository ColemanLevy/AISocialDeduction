// Fill out your copyright notice in the Description page of Project Settings.


#include "GetBodyLocation.h"
#include "AIDeductionGameMode.h"
#include "CrewMateController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UGetBodyLocation::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory)
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());

	if (crewmateController)
	{
		UBlackboardComponent* blackboardComp = crewmateController->GetBlackboardComp();

		// Gets the currently seen dead body
		blackboardComp->SetValueAsObject("LocationToGo", crewmateController->_crewmateNPC->_deadBody);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
