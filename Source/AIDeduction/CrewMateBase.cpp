// Fill out your copyright notice in the Description page of Project Settings.


#include "CrewmateBase.h"
#include "CrewmateController.h"
#include "AIDeductionGameMode.h"

#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"

// Sets default values
ACrewMateBase::ACrewMateBase()
{
	// Add the perception component to the crewmate.
	perceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("perceptionComp"));

	//Research later on how to get component working through C++.
}

// Called when the game starts or when spawned
void ACrewMateBase::BeginPlay()
{
	Super::BeginPlay();

	aiDeductionGameMode = Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode());
	aiDeductionGameMode->crewMates.Add(this); // Add this crewmate to the list of all crewmates
}

// Function that will handle what a crewmate will do when it sees another crewmate
void ACrewMateBase::OnCrewmateSeen(APawn* crewmate)
{
}

