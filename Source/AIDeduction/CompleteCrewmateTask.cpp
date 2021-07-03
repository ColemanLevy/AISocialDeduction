// Fill out your copyright notice in the Description page of Project Settings.


#include "CompleteCrewmateTask.h"
#include "AIDeductionGameMode.h"
#include "CrewMateBase.h"
#include "CrewMateController.h"

// Indicates to the GameMode that a task has been completed
EBTNodeResult::Type UCompleteCrewmateTask::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory)
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());

	if (crewmateController && (crewmateController->_numberOfCompletedTasks < crewmateController->_tasks.Num()))
	{
		++(crewmateController->_numberOfCompletedTasks);
		crewmateController->_crewmateNPC->ResetTaskProgress();

		// Check for an Innocent victory whenever a task is completed
		crewmateController->_aiDeductionGameMode->CheckTaskVictory();

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}