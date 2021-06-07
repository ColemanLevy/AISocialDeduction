// Copyright Epic Games, Inc. All Rights Reserved.


#include "AIDeductionGameMode.h"
#include "AIDeductionCharacter.h"
#include "CrewMateController.h"
#include "PlayerSpectator.h"

#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "Blueprint/UserWidget.h"

// Constructor for the game mode class.
AAIDeductionGameMode::AAIDeductionGameMode()
{
	// Set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Called when the game starts or when spawned
void AAIDeductionGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Get all the waypoints in the level for providing to crewmates.
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), wayPointsClass, wayPoints);
	
	// Create the main menu UI
	mainMenu = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), mainMenuClass, TEXT("MainMenu"));
	mainMenu->AddToViewport();
}

// Provides a random waypoint for use by the crewmates' meandering
AActor* AAIDeductionGameMode::GetRandomWaypoint()
{
	int randomInt = FMath::RandRange(0, wayPoints.Num());

	return wayPoints[randomInt];
}

// Indicates to all the crewmates and the player controller that the simulation has begun.
void AAIDeductionGameMode::StartGame()
{
	for (ACrewMateBase* crewMate : crewMates)
	{
		Cast<ACrewMateController>(crewMate->GetController())->StartAI();
	}

	mainMenu->SetVisibility(ESlateVisibility::Collapsed);

	gameStarted = true;
}

// Indicates to all the crewmates and the player controller that the simulation is done and they should all
// reset to initial positions and memory.
void AAIDeductionGameMode::ResetGame()
{
	for (ACrewMateBase* crewMate : crewMates)
	{
		Cast<ACrewMateController>(crewMate->GetController())->ResetAI();
	}

	playerSpectator->ResetTransform();

	mainMenu->SetVisibility(ESlateVisibility::Visible);

	gameStarted = false;
}

// Sets the reference to the player-controlled pawn
void AAIDeductionGameMode::SetPlayerSpectator(APlayerSpectator* newPlayerSpectator)
{
	playerSpectator = Cast<APlayerSpectator>(newPlayerSpectator);
}
