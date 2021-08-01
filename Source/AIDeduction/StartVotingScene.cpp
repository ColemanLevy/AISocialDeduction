// Fill out your copyright notice in the Description page of Project Settings.


#include "StartVotingScene.h"
#include "AIDeductionGameMode.h"
#include "CrewMateController.h"
#include "CrewMateBase.h"

EBTNodeResult::Type UStartVotingScene::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory)
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());

	if (crewmateController)
	{
		ACrewMateBase* crewmateBase = crewmateController->_crewmateNPC;
		crewmateController->_aiDeductionGameMode->StartVotingScene(crewmateBase->_victimInformation, crewmateBase->_name);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
