// Fill out your copyright notice in the Description page of Project Settings.


#include "StartCrewmateTask.h"
#include "TaskBase.h"
#include "CrewMateBase.h"
#include "CrewMateController.h"

#include "BehaviorTree/BlackboardComponent.h"

// Function which informs the Crewmate they've started a new task.
EBTNodeResult::Type UStartCrewmateTask::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory)
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());

	if (crewmateController && (crewmateController->_numberOfCompletedTasks < crewmateController->_tasks.Num()))
	{
		UBlackboardComponent* blackboardComp = crewmateController->GetBlackboardComp();

		ATaskBase* task = Cast<ATaskBase>(blackboardComp->GetValueAsObject(FName("LocationToGo")));

		// Sets the Crewmate up to wait the amount of time the task is set to take to perform.
		if (task)
		{
			blackboardComp->SetValueAsFloat("TimeToWait", task->timeToPerform);
			crewmateController->_crewmateNPC->StartTask(task->timeToPerform);

			return EBTNodeResult::Succeeded;
		}

		return EBTNodeResult::Failed;
		
	}

	return EBTNodeResult::Failed;
}