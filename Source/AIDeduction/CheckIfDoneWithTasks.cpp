// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckIfDoneWithTasks.h"
#include "CrewMateController.h"

// Checks if the crewmate in question has completed all their tasks
bool UCheckIfDoneWithTasks::CalculateRawConditionValue(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) const
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());

	return ((crewmateController->_numberOfCompletedTasks >= crewmateController->_tasks.Num()) || !crewmateController);
}