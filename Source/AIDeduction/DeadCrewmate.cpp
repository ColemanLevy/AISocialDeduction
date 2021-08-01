// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadCrewmate.h"
#include "AIDeductionGameMode.h"

// Sets default values
ADeadCrewmate::ADeadCrewmate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeadCrewmate::BeginPlay()
{
	Super::BeginPlay();
	
	Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode())->_deadBodies.Add(this);
}

// Called every frame
void ADeadCrewmate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FCrewmateInformation ADeadCrewmate::GetSeen()
{
	return _deathInformation;
}

