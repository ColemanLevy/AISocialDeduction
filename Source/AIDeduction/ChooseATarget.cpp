// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseATarget.h"
#include "CrewMateBase.h"
#include "CrewMateController.h"

#include "BehaviorTree/BlackboardComponent.h"

// Chooses a nearby Crewmate in sight to be a target for a potential kill
EBTNodeResult::Type UChooseATarget::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory)
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());

	if (crewmateController)
	{
		int numberOfCrewmatesChecked = 0;
		int numCrewmatesInSight = crewmateController->_crewmatesInSight.Num();
		ACrewMateBase* target = nullptr;
		ACrewMateBase* potentialTarget = nullptr;

		// Chooses the first Innocent crewmate in sight to be the target for the kill.
		while (!target && numberOfCrewmatesChecked < numCrewmatesInSight)
		{
			potentialTarget = crewmateController->_crewmatesInSight[numberOfCrewmatesChecked];
			if (!potentialTarget->_isKiller && potentialTarget->_isAlive)
			{
				target = potentialTarget;
			}

			++numberOfCrewmatesChecked;
		}

		UBlackboardComponent* blackboardComp = crewmateController->GetBlackboardComp();

		// Sets the Killer to chase after the target crewmate
		blackboardComp->SetValueAsObject("LocationToGo", target);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}