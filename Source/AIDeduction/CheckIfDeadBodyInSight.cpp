// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckIfDeadBodyInSight.h"
#include "CrewMateController.h"
#include "CrewMateBase.h"

bool UCheckIfDeadBodyInSight::CalculateRawConditionValue(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) const
{
	ACrewMateController* crewmateController = Cast<ACrewMateController>(ownerComponent.GetAIOwner());

	return (crewmateController->_crewmateNPC->_bodyInSight);
}
