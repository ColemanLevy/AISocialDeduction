// Fill out your copyright notice in the Description page of Project Settings.


#include "CrewMateController.h"
#include "CrewMateBase.h"
#include "AIDeductionGameMode.h" 

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

// Constructor for the class
ACrewMateController::ACrewMateController()
{
	//Initialize blackboard and behavior tree
	behaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("behaviorComp"));
	blackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("blackboardComp"));

	//Initialize blackboard keys
	LocationToGoKey = "LocationToGo";
}

// Called when the game starts or when spawned
void ACrewMateController::BeginPlay()
{
	Super::BeginPlay();

	gameMode = Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode());
}

// Function which occurs when the controller possesses a pawn
void ACrewMateController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	//Get reference to the crewmate
	crewmateNPC = Cast<ACrewMateBase>(pawn);

	if (crewmateNPC)
	{
		// Grab its initial transform and initialize its blackboard
		startingTransform = crewmateNPC->GetTransform();

		if (crewmateNPC->behaviorTree->BlackboardAsset)
		{
			blackboardComp->InitializeBlackboard(*(crewmateNPC->behaviorTree->BlackboardAsset));
		}
	}
}

// Function to start the behavior tree of the crewmate
void ACrewMateController::StartAI()
{
	behaviorComp->StartTree(*(crewmateNPC->behaviorTree));
}

// FFunction to reset the crewmate to an initial position, wipe its memories, and stop its behavior tree
void ACrewMateController::ResetAI()
{
	crewmateNPC->SetActorTransform(startingTransform);
	behaviorComp->StopTree();
}
