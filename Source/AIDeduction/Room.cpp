// Fill out your copyright notice in the Description page of Project Settings.


#include "Room.h"
#include "CrewMateBase.h"

#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
ARoom::ARoom()
{
	_collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("collisionBox"));
	_collisionBox->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));
	_collisionBox->SetCollisionProfileName("Trigger");

	RootComponent = _collisionBox;
}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();

	_collisionBox->OnComponentBeginOverlap.AddDynamic(this, &ARoom::OnBoxBeginOverlap);
}

// Function that checks if what entered the room was a Crewmate, and if so, inform said Crewmate they've entered a new room.
void ARoom::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACrewMateBase* crewmate = Cast<ACrewMateBase>(OtherActor);

	if (crewmate)
	{
		crewmate->EnterNewRoom(_roomName);
	}
}

