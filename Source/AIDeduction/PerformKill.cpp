// Fill out your copyright notice in the Description page of Project Settings.


#include "PerformKill.h"
#include "AIDeductionGameMode.h"
#include "CrewMateController.h"
#include "CrewMateBase.h"

#include "BehaviorTree/BlackboardComponent.h"

// Function where a Killer attempts to kill an Innocent target.
EBTNodeResult::Type UPerformKill::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory)
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());

	if (crewmateController)
	{
		int numberOfInnocentsInView = 0;

		for (auto crewmate : crewmateController->_crewmatesInSight)
		{
			if (!crewmate->_isKiller)
			{
				++numberOfInnocentsInView;
			}
		}

		// Only performs kill if there are no other Innocent Crewmates around to report the killer.
		if (numberOfInnocentsInView <= 1)
		{
			UBlackboardComponent* blackboardComp = crewmateController->GetBlackboardComp();

			ACrewMateBase* targetCrewmate = Cast<ACrewMateBase>(blackboardComp->GetValueAsObject(FName("LocationToGo")));

			if (targetCrewmate && targetCrewmate->_isAlive)
			{
				targetCrewmate->_crewmateController->GetKilled();

				crewmateController->_aiDeductionGameMode->CheckKillerVictory();
			}
		}

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}