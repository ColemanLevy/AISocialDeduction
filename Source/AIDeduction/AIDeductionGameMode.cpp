// Copyright Epic Games, Inc. All Rights Reserved.


#include "AIDeductionGameMode.h"
#include "AIDeductionCharacter.h"
#include "CrewMateController.h"
#include "PlayerSpectator.h"

#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "Blueprint/UserWidget.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

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
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), _wayPointsClass, _wayPoints);

	// Get all the waypoints in the level for providing to crewmates.
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), _taskClass, _tasks);
	
	// Create the main menu UI
	_mainMenu = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), _mainMenuClass, TEXT("MainMenu"));
	_mainMenu->AddToViewport();

	// Create the victory screen
	_victoryScreen = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), _victoryScreenClass, TEXT("VictoryScreen"));
	_victoryScreen->AddToViewport();
	_victoryScreen->SetVisibility(ESlateVisibility::Collapsed);

	// Create the victory screen
	_votingScreen = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), _votingScreenClass, TEXT("VotingScreen"));
	_votingScreen->AddToViewport();
	_votingScreen->SetVisibility(ESlateVisibility::Collapsed);
}

// Provides a random waypoint for use by the crewmates' meandering
AActor* AAIDeductionGameMode::GetRandomWaypoint()
{
	int randomInt = FMath::RandRange(0, _wayPoints.Num() - 1);

	return _wayPoints[randomInt];
}

// Check if the innocents have completed all their tasks when a task is completed
void AAIDeductionGameMode::CheckInnocentVictory(bool taskCompleted)
{
	if (taskCompleted)
	{
		++_totalNumberOfCompletedTasks;
	}

	if (_totalNumberOfCompletedTasks >= _totalNumberOfTasks || _numberOfKillers <= 0)
	{
		InnocentVictory();
	}
}

// Enact the Innocent Victory by pausing the game and showing the victory screen
void AAIDeductionGameMode::InnocentVictory()
{
	_observingCrewmate = nullptr;
	_victoryReached = true;

	SetVictoryScreen(VictoryTypeEnum::InnocentVictory);
	PauseGame();
	_victoryScreen->SetVisibility(ESlateVisibility::Visible);
}

// Check if the Killer has killed enough Innocents to have won the game
void AAIDeductionGameMode::CheckKillerVictory()
{
	--_numberOfAliveCrewmates;

	if ((_numberOfKillers * 2) >= _numberOfAliveCrewmates)
	{
		KillerVictory();
	}
}

// Enact the Killer Victory by pausing the game and showing the victory screen
void AAIDeductionGameMode::KillerVictory()
{
	_observingCrewmate = nullptr;
	_victoryReached = true;

	SetVictoryScreen(VictoryTypeEnum::KillerVictory);
	PauseGame();
	_victoryScreen->SetVisibility(ESlateVisibility::Visible);
}

void AAIDeductionGameMode::ShowHideKnowledge()
{
	if (_gameStarted && !_victoryReached && !_votingSceneOngoing)
	{
		if (_observingCrewmate)
		{
			_observingCrewmate = nullptr;
		}
		else
		{
			_observingCrewmate = _crewMates[_observingCrewmateNum]->_crewmateNPC;
			ReloadKnowledgeList();
		}
	}
}

void AAIDeductionGameMode::ObserveNextCrewmate()
{
	if (_gameStarted && !_victoryReached && !_votingSceneOngoing)
	{
		if (_observingCrewmateNum >= (_crewMates.Num() - 1))
		{
			_observingCrewmateNum = 0;
		}
		else
		{
			++_observingCrewmateNum;
		}

		_observingCrewmate = _crewMates[_observingCrewmateNum]->_crewmateNPC;

		ReloadKnowledgeList();
	}
}

void AAIDeductionGameMode::ObservePreviousCrewmate()
{
	if (_gameStarted && !_victoryReached && !_votingSceneOngoing)
	{
		if (_observingCrewmateNum <= 0)
		{
			_observingCrewmateNum = _crewMates.Num() - 1;
		}
		else
		{
			--_observingCrewmateNum;
		}

		_observingCrewmate = _crewMates[_observingCrewmateNum]->_crewmateNPC;

		ReloadKnowledgeList();
	}
}

ACrewMateBase* AAIDeductionGameMode::RetrieveCrewmate(CrewmateColorEnum crewmateName)
{
	for (ACrewMateController* crewmate : _crewMates)
	{
		if (crewmate->_crewmateNPC->_name == crewmateName)
		{
			return crewmate->_crewmateNPC;
		}
	}

	return nullptr;
}

// Indicates to all the crewmates and the player controller that the simulation has begun.
void AAIDeductionGameMode::StartGame()
{
	_gameStartTime = GetGameTimeSinceCreation();
	_numberOfAliveCrewmates = _crewMates.Num();
	_numberOfKillers = 0;
	_totalNumberOfCompletedTasks = 0;

	// Record the number of Killers amongst the crewmates
	for (ACrewMateController* crewMate : _crewMates)
	{
		if (crewMate->_crewmateNPC->_isKiller)
		{
			++_numberOfKillers;
		}

		int numberOfTasksInScene = _tasks.Num();

		// Distribute tasks amongst the crewmates
		while (crewMate->_tasks.Num() < _numberOfTasksToAssign)
		{
			crewMate->_tasks.AddUnique(Cast<ATaskBase>(_tasks[FMath::RandRange(0, numberOfTasksInScene - 1)]));
		}

		crewMate->StartAI();
	}
	
	_totalNumberOfTasks = _numberOfTasksToAssign * (_crewMates.Num() - _numberOfKillers);

	_mainMenu->SetVisibility(ESlateVisibility::Collapsed);

	_gameStarted = true;
}

// Pausing and resuming the game on hitting the Pause Button (P)
void AAIDeductionGameMode::PauseButton()
{
	if (_gameStarted)
	{
		if (_gamePaused)
		{
			ResumeGame();
		}
		else
		{
			PauseGame();
		}
	}
}

// Pause the game by pausing the logic of all of the crewmates
void AAIDeductionGameMode::PauseGame()
{
	if (!_gamePaused)
	{
		for (ACrewMateController* crewMate : _crewMates)
		{
			crewMate->_behaviorComp->PauseLogic(TEXT("Game was paused."));
			crewMate->_crewmateNPC->Pause();
		}

		_gamePaused = true;
	}
}

// Resume the game by resuming the logic of all the crewmates
void AAIDeductionGameMode::ResumeGame()
{
	if (_gamePaused)
	{
		for (ACrewMateController* crewMate : _crewMates)
		{
			crewMate->_behaviorComp->ResumeLogic(TEXT("Game was resumed."));
			crewMate->_crewmateNPC->Resume();
		}

		_gamePaused = false;
	}
}

// Indicates to all the crewmates and the player controller that the simulation is done and they should all
// reset to initial positions and memory.
void AAIDeductionGameMode::ResetGame()
{
	if (!_votingSceneOngoing)
	{
		ResumeGame();

		for (ACrewMateController* crewMate : _crewMates)
		{
			crewMate->ResetAI();
		}

		_observingCrewmate = nullptr;

		_playerSpectator->ResetTransform();

		_mainMenu->SetVisibility(ESlateVisibility::Visible);

		_gameStarted = false;
		_victoryReached = false;
	}
}

void AAIDeductionGameMode::StartVotingScene(FCrewmateInformation victimInformation, CrewmateColorEnum bodyFinder)
{
	for (ACrewMateController* crewMate : _crewMates)
	{
		crewMate->CrewmateDiscussionSetUp();
	}

	for (AActor* body : _deadBodies)
	{
		body->Destroy();
	}

	_deadBodies.Empty();

	_victimInformation = victimInformation;
	_bodyFinder = bodyFinder;

	_votingScreen->SetVisibility(ESlateVisibility::Visible);

	_observingCrewmate = nullptr;
	_votingSceneOngoing = true;

	DiscussionSceneLoop();
}

void AAIDeductionGameMode::EndVotingScene()
{
	for (ACrewMateController* crewMate : _crewMates)
	{
		crewMate->CrewmateDiscussionOver();
	}

	_lastTimeSeenAlive = 0;
	_suspects.Empty();

	_votingScreen->SetVisibility(ESlateVisibility::Collapsed);
	_votingSceneOngoing = false;
}

// Sets the reference to the player-controlled pawn
void AAIDeductionGameMode::SetPlayerSpectator(APlayerSpectator* newPlayerSpectator)
{
	_playerSpectator = Cast<APlayerSpectator>(newPlayerSpectator);
}
