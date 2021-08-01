// Fill out your copyright notice in the Description page of Project Settings.


#include "CrewMateController.h"
#include "AIDeductionGameMode.h" 
#include "DeadCrewmate.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"

// Constructor for the class
ACrewMateController::ACrewMateController()
{
	//Initialize blackboard and behavior tree
	_behaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("behaviorComp"));
	_blackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("blackboardComp"));

	//Initialize blackboard keys
	LocationToGoKey = "LocationToGo";
}

// Called when the game starts or when spawned
void ACrewMateController::BeginPlay()
{
	Super::BeginPlay();

	_aiDeductionGameMode = Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode());
	_aiDeductionGameMode->_crewMates.Add(this); // Add this crewmate to the list of all crewmates
}

// Function which occurs when the controller possesses a pawn
void ACrewMateController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	//Get reference to the crewmate
	_crewmateNPC = Cast<ACrewMateBase>(pawn);

	if (_crewmateNPC)
	{
		_crewmateNPC->_crewmateController = this;

		// Grab its initial transform and initialize its blackboard
		_startingTransform = _crewmateNPC->GetTransform();

		if (_crewmateNPC->_behaviorTree->BlackboardAsset)
		{
			_blackboardComp->InitializeBlackboard(*(_crewmateNPC->_behaviorTree->BlackboardAsset));
		}
	}
}

// Function to start the behavior tree of the crewmate
void ACrewMateController::StartAI()
{
	_behaviorComp->StartTree(*(_crewmateNPC->_behaviorTree));
	_crewmateNPC->Revive();
}

// Function to reset the crewmate to an initial position, wipe its memories, and stop its behavior tree
void ACrewMateController::ResetAI()
{
	_behaviorComp->StopTree();
	_crewmateNPC->ResetPerception();
	_crewmatesInSight.Empty();
	_crewmateNPC->_observedKnowledge.Empty();
	_crewmateNPC->_totalForgottenMemories = 0;

	_crewmateNPC->SetActorTransform(_startingTransform);
	
	_crewmateNPC->ResetTaskProgress();
	_tasks.Empty();
	_numberOfCompletedTasks = 0;

	_crewmateNPC->_crewmateInformation.roomIn = RoomEnum::Cafeteria;
	_crewmateNPC->_crewmateInformation.roomOut = RoomEnum::None;
}

void ACrewMateController::CrewmateDiscussionSetUp()
{
	_behaviorComp->StopTree();

	if (_crewmateNPC->_isAlive)
	{
		_crewmateNPC->ResetPerception();
		_crewmatesInSight.Empty();
	}

	_crewmateNPC->SetActorTransform(_startingTransform);

	_crewmateNPC->ResetTaskProgress();

	_crewmateNPC->_crewmateInformation.roomIn = RoomEnum::Cafeteria;
	_crewmateNPC->_crewmateInformation.roomOut = RoomEnum::None;

	_crewmateNPC->_deadBody = nullptr;
	_crewmateNPC->_bodyInSight = false;
}

void ACrewMateController::CrewmateDiscussionOver()
{
	if (_crewmateNPC->_isAlive)
	{
		_crewmateNPC->StartPerception();
	}
	_behaviorComp->StartTree(*(_crewmateNPC->_behaviorTree));
}

// Function which handles what occurs when a Killer kills the Crewmate this controller manages.
void ACrewMateController::GetKilled()
{
	_behaviorComp->StopTree();

	_crewmateNPC->Die();
	_crewmatesInSight.Empty();

	_behaviorComp->StartTree(*(_crewmateNPC->_behaviorTree));
}

// Grabs the next unfinished task from the randomized list to perform.
AActor* ACrewMateController::GetNextUnfinishedTask()
{
	int nextTask = std::min(_numberOfCompletedTasks, (_tasks.Num() - 1));

	return _tasks[nextTask];
}

// Function which increments the number of tasks this Crewmate has completed.
void ACrewMateController::TaskCompleted()
{
	++_numberOfCompletedTasks;
}

// Adds a seen Crewmate to the list of Crewmates in sight.
void ACrewMateController::CrewmateSeen(ACrewMateBase* crewmate)
{
	_crewmatesInSight.Add(crewmate);
}

// Removes a Crewmate from the list of Crewmates in sight.
void ACrewMateController::CrewmateUnseen(ACrewMateBase* crewmate)
{
	_crewmatesInSight.Remove(crewmate);
}

FCrewmateInformation ACrewMateController::RememberRoom(RoomEnum room)
{
	int minTimeFrame = _aiDeductionGameMode->_lastTimeSeenAlive - _aiDeductionGameMode->_timeFrame;
	int maxTimeFrame = _aiDeductionGameMode->_lastTimeSeenAlive + _aiDeductionGameMode->_timeFrame;

	FCrewmateInformation currentInformation;

	for (int i = 0; i < _crewmateNPC->_observedKnowledge.Num(); ++i)
	{
		currentInformation = _crewmateNPC->_observedKnowledge[i];

		if (currentInformation.simulationTime >= minTimeFrame && currentInformation.simulationTime <= maxTimeFrame)
		{
			if ((currentInformation.roomIn == room || currentInformation.roomOut == room) && !currentInformation.forgotten
				&& currentInformation.crewmateName != _aiDeductionGameMode->_victimInformation.crewmateName
				&& (!_crewmateNPC->_isKiller || !_aiDeductionGameMode->RetrieveCrewmate(currentInformation.crewmateName)->_isKiller))
			{
				if (_aiDeductionGameMode->RetrieveCrewmate(currentInformation.crewmateName)->_isAlive)
				{
					return currentInformation;
				}
			}
		}
	}

	return FCrewmateInformation();
}

FCrewmateInformation ACrewMateController::RememberCrewmate(CrewmateColorEnum crewmateName)
{
	FCrewmateInformation currentInformation;

	for (int i = 0; i < _crewmateNPC->_observedKnowledge.Num(); ++i)
	{
		currentInformation = _crewmateNPC->_observedKnowledge[i];

		if (currentInformation.crewmateName == crewmateName && !currentInformation.forgotten 
			&& (!_crewmateNPC->_isKiller || currentInformation.roomIn != _aiDeductionGameMode->_victimInformation.roomIn))
		{
			return _crewmateNPC->_observedKnowledge[i];
		}
	}

	return FCrewmateInformation();
}
