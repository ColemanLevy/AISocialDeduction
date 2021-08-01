// Fill out your copyright notice in the Description page of Project Settings.


#include "CrewmateBase.h"
#include "CrewmateController.h"
#include "DeadCrewmate.h"
#include "AIDeductionGameMode.h"

#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"

#define CHANCE_TO_LOSE_MEMORY 33
#define MIN_NUM_OF_MEMORIES 10

// Sets default values
ACrewMateBase::ACrewMateBase()
{
}

// Called when the game starts or when spawned
void ACrewMateBase::BeginPlay()
{
	Super::BeginPlay();

	_aiDeductionGameMode = Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode());
	GetTaskProgressBar();

	InitializeMemorySystem();

	_crewmateInformation.crewmateName = _name;
	_crewmateInformation.roomIn = RoomEnum::Cafeteria;
	_crewmateInformation.roomOut = RoomEnum::None;
}

// Function that will handle what a crewmate will do when it sees another crewmate
void ACrewMateBase::OnSeenCrewmateUpdate(AActor* crewmate, bool sensed)
{
	ACrewMateBase* castedCrewmate = Cast<ACrewMateBase>(crewmate);

	if (castedCrewmate)
	{
		if (sensed)
		{
			_crewmateController->CrewmateSeen(castedCrewmate);
			_observedKnowledge.Insert((castedCrewmate->GetSeen()), 0);

			if (_aiDeductionGameMode->_observingCrewmate && (_name == _aiDeductionGameMode->_observingCrewmate->_name))
			{
				// Record what room the crewmate was seen in
				_aiDeductionGameMode->ReloadKnowledgeList();
			}
		}
		else
		{
			_crewmateController->CrewmateUnseen(castedCrewmate);
		}

		return;
	}

	ADeadCrewmate* deadCrewmate = Cast<ADeadCrewmate>(crewmate);

	if (deadCrewmate && _isAlive && !_isKiller)
	{
		_crewmateController->_behaviorComp->StopTree();
		_bodyInSight = true;
		_victimInformation = deadCrewmate->GetSeen();

		_deadBody = deadCrewmate;
		_crewmateController->_behaviorComp->StartTree(*_behaviorTree);
	}
}

// Function that passes out information to observing crewmates when the current crewmate enters
void ACrewMateBase::EnterNewRoom(RoomEnum newRoom)
{
	_crewmateInformation.simulationTime = int(truncf(GetGameTimeSinceCreation() - _aiDeductionGameMode->_gameStartTime));
	_crewmateInformation.roomOut = _currentRoom;
	_crewmateInformation.roomIn = newRoom;
	_currentRoom = newRoom;

	SendOutMovementInfo();

	_crewmateInformation.roomOut = RoomEnum::None;
}

// Send out the current Crewmate information of this crewmate to every other crewmate in sight
void ACrewMateBase::SendOutMovementInfo()
{
	for (ACrewMateBase* visibleCrewmate : _crewmateController->_crewmatesInSight)
	{
		visibleCrewmate->ReceiveMovementInfo(_crewmateInformation);
	}
}

// The main function for the memory system. This handles marking a Crewmates memories as forgotten if said Crewmate
// actually hits the random chance to forget.
void ACrewMateBase::AttemptToForget()
{
	if (FMath::RandRange(0, 99) < _aiDeductionGameMode->_chanceToForget && _totalForgottenMemories < (_observedKnowledge.Num() - MIN_NUM_OF_MEMORIES))
	{
		int memoriesForgotten = 0;
		int traverseDirection = -1;
		int iterator = _observedKnowledge.Num() - 1;
		int firstMemory = _observedKnowledge.Num() - 1;

		// Bounces back and forth starting at the oldest memories until 2 memories have been forgotten. Each memory passed over
		// has a 33% chance to be forgotten.
		while (memoriesForgotten < 2)
		{
			if (FMath::RandRange(0, 99) < CHANCE_TO_LOSE_MEMORY && !_observedKnowledge[iterator].forgotten)
			{
				_observedKnowledge[iterator].forgotten = true;
				++memoriesForgotten;
				++_totalForgottenMemories;
			}

			if (iterator >= firstMemory)
			{
				traverseDirection = -1;
			}
			else if (iterator <= 0)
			{
				traverseDirection = 1;
			}

			iterator += traverseDirection;
		}

		// Once memories have been forgotten, reload the Knowledge list on the UI so forgotten memories show up red.
		if (_aiDeductionGameMode->_observingCrewmate && (_name == _aiDeductionGameMode->_observingCrewmate->_name))
		{
			_aiDeductionGameMode->ReloadKnowledgeList();
		}
	}
}

// Function for handling the recording of any recieved movement information
void ACrewMateBase::ReceiveMovementInfo(const FCrewmateInformation& movementInfo)
{
	_observedKnowledge.Insert(movementInfo, 0);

	if (_aiDeductionGameMode->_observingCrewmate && (_name == _aiDeductionGameMode->_observingCrewmate->_name))
	{
		_aiDeductionGameMode->ReloadKnowledgeList();
	}
}

// Sends out the current Crewmate information of this crewmate to the crewmate who is requesting this information on sight
const FCrewmateInformation& ACrewMateBase::GetSeen()
{
	_crewmateInformation.simulationTime = int(truncf(GetGameTimeSinceCreation() - _aiDeductionGameMode->_gameStartTime));

	return _crewmateInformation;
}

void ACrewMateBase::FinishEject()
{
	_ejected = false;
	SetActorTransform(_crewmateController->_startingTransform);
	ResetMesh();
}
