// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CrewMateBase.h"
#include "CrewMateController.h"

#include "AIDeductionGameMode.generated.h"

UENUM(BlueprintType)
/// <summary>
/// Enum for indicating what type of Victory has occured in-game
/// </summary>
enum class VictoryTypeEnum : uint8
{
	InnocentVictory,
	KillerVictory
};

/**
 * The game mode used in the simulation.
 */
UCLASS(minimalapi)
class AAIDeductionGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	/// <summary>
	/// Called when the game starts or when spawned
	/// </summary>
	virtual void BeginPlay() override;

public:
	/// <summary>
	/// Constructor for the class
	/// </summary>
	AAIDeductionGameMode();

	/// <summary>
	/// Returns a single random waypoint from the list of all waypoints in the scene.
	/// </summary>
	/// <returns>One of the waypoints in the scene.</returns>
	AActor* GetRandomWaypoint();

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function for checking if the innocents have compeleted enough tasks to win the simulation.
		/// </summary>
		void CheckInnocentVictory(bool taskCompleted);
	/// <summary>
	/// Function for enacting and indicating that the inoccents have won the simulation.
	/// </summary>
	void InnocentVictory();

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function for checking if the killers have killed enough innocents to win the simulation.
		/// </summary>
		void CheckKillerVictory();
	/// <summary>
	/// Function for enacting and indicating that the innocents have won the simulation.
	/// </summary>
	void KillerVictory();

	/// <summary>
	/// Function for displaying and hiding the Knowledge Bar.
	/// </summary>
	void ShowHideKnowledge();

	/// <summary>
	/// Function for grabbing the next Crewmate in the list of Crewmates and displaying their knowledge.
	/// </summary>
	void ObserveNextCrewmate();
	/// <summary>
	/// Function for grabbing the previous Crewmate in the list of Crewmates and displaying their knowledge.
	/// </summary>
	void ObservePreviousCrewmate();

	UFUNCTION(BlueprintCallable)
		ACrewMateBase* RetrieveCrewmate(CrewmateColorEnum crewmateName);

	UFUNCTION(BlueprintImplementableEvent)
		/// <summary>
		/// Function for changing the Victory screen based on if Innocents or Killers won the simulation.
		/// </summary>
		/// <param name="innocentVictory"></param>
		void SetVictoryScreen(VictoryTypeEnum innocentVictory);

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function to initialize and start the simulation.
		/// </summary>
		void StartGame();

	UFUNCTION()
		/// <summary>
		/// Function for pausing and resuming the simulation when the player hits the pause button. (P)
		/// </summary>
		void PauseButton();

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function for un-pausing the AI in the simulation.
		/// </summary>
		void ResumeGame();

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function for pausing the AI in the simulation.
		/// </summary>
		void PauseGame();

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function to return all of the crewmates and the player camera to their initial positions, and wipe all of the crewmates memories.
		/// </summary>
		void ResetGame();

	UFUNCTION()
		void StartVotingScene(FCrewmateInformation victimInformation, CrewmateColorEnum bodyFinder);

	UFUNCTION(BlueprintCallable)
		void EndVotingScene();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void VotingSceneLoop();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void DiscussionSceneLoop();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void EjectionScene(ACrewMateBase* crewmate);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void EjectionSceneFinished(ACrewMateBase* crewmate);

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Sets the reference to the PlayerSpectator for the game mode.
		/// </summary>
		/// <param name="newPlayerCamera">The new PlayerSpectator to refer to.</param>
		void SetPlayerSpectator(APlayerSpectator* newPlayerCamera);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		/// <summary>
		/// Function for reloading Knowledge Entries into the Knowledge List on the Simulation UI.
		/// </summary>
		void ReloadKnowledgeList();

	UFUNCTION(BlueprintImplementableEvent)
		/// <summary>
		/// Function for scrolling the Knowledge List up or down on the UI.
		/// </summary>
		/// <param name="distance">The amount to scroll the list by.</param>
		void ScrollKnowledgeList(float distance);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Map")
		/// <summary>
		/// The list of all waypoints in the simulation.
		/// </summary>
		TArray<AActor*> _wayPoints;
	UPROPERTY(EditAnywhere, Category = "Map")
		/// <summary>
		/// The class of what the waypoints are. This is set in the game mode's blueprint and indicates to what the 
		/// game mode should be looking for when filling the list of waypoint references.
		/// </summary>
		TSubclassOf<AActor> _wayPointsClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Map")
		/// <summary>
		/// The list of all task spots in the simulation.
		/// </summary>
		TArray<AActor*> _tasks;
	UPROPERTY(EditAnywhere, Category = "Map")
		/// <summary>
		/// The class of what the tasks are. This is set in the game mode's blueprint and indicates to what the 
		/// game mode should be looking for when filling the list of waypoint references.
		/// </summary>
		TSubclassOf<AActor> _taskClass;

	/// <summary>
	/// Reference to the main menu screen UI.
	/// </summary>
	UUserWidget* _mainMenu;

	UPROPERTY(EditAnywhere, Category = "UI")
		/// <summary>
		/// The class type of the main menu, used to indicate what type of UI should be created for the main menu.
		/// </summary>
		TSubclassOf<UUserWidget> _mainMenuClass;

	UPROPERTY(BlueprintReadOnly, Category = "UI")
		/// <summary>
		/// Reference to the victory screen UI.
		/// </summary>
		UUserWidget* _victoryScreen;

	UPROPERTY(EditAnywhere, Category = "UI")
		/// <summary>
		/// The class type of the victory screen, used to indicate what type of UI should be created for the victory screen.
		/// </summary>
		TSubclassOf<UUserWidget> _victoryScreenClass;

	UPROPERTY(BlueprintReadOnly, Category = "UI")
		/// <summary>
		/// Reference to the voting screen UI.
		/// </summary>
		UUserWidget* _votingScreen;

	UPROPERTY(EditAnywhere, Category = "UI")
		/// <summary>
		/// The class type of the voting screen, used to indicate what type of UI should be created for the voting screen.
		/// </summary>
		TSubclassOf<UUserWidget> _votingScreenClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
		/// <summary>
		/// List of all the crewmates in the game.
		/// </summary>
		TArray<ACrewMateController*> _crewMates;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
		TArray<AActor*> _deadBodies;

	UPROPERTY(BlueprintReadWrite)
		FCrewmateInformation _victimInformation;

	UPROPERTY(BlueprintReadWrite)
		CrewmateColorEnum _bodyFinder;

	UPROPERTY(BlueprintReadOnly)
		/// <summary>
		/// The total of all tasks given to Innocents.
		/// </summary>
		int _totalNumberOfTasks = 0;
	UPROPERTY(BlueprintReadOnly)
		/// <summary>
		/// The number of tasks that the Innocents have completed.
		/// </summary>
		int _totalNumberOfCompletedTasks = 0;

	UPROPERTY(BlueprintReadWrite)
		/// <summary>
		/// The number of Killers in a round of simulation.
		/// </summary>
		int _numberOfKillers = 0;

	/// <summary>
	/// The number of crewmates still alive in the simulation round.
	/// </summary>
	int _numberOfAliveCrewmates = 0;

	UPROPERTY(BlueprintReadOnly)
		/// <summary>
		/// Reference to the PlayerSpectator, which is the pawn the player has control of in the game.
		/// </summary>
		class APlayerSpectator* _playerSpectator;

	UPROPERTY(BlueprintReadOnly)
		/// <summary>
		/// Boolean to indicate a round of the simulation is in session.
		/// </summary>
		bool _gameStarted = false;

	UPROPERTY(BlueprintReadOnly)
		/// <summary>
		/// Boolean to indicate a round of the simulation is paused.
		/// </summary>
		bool _gamePaused = false;

	UPROPERTY(BlueprintReadOnly)
		bool _votingSceneOngoing = false;

	UPROPERTY(BlueprintReadOnly)
		/// <summary>
		/// Bool for indicating to the Player Spectator and Crewmates that the simulation round has been won.
		/// </summary>
		bool _victoryReached = false;

	UPROPERTY(BlueprintReadWrite, Category = "AI")
		/// <summary>
		/// The crewmate whose Knowledge is displayed on the simulation UI.
		/// </summary>
		ACrewMateBase* _observingCrewmate = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "AI")
		/// <summary>
		/// The index of the Crewmate being currently observed in the list of Crewmates.
		/// </summary>
		int _observingCrewmateNum = 0;

	UPROPERTY()
		/// <summary>
		/// The time at which a round was started
		/// </summary>
		float _gameStartTime = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		/// <summary>
		/// The chance that an Innocent crewmate will choose to meander around the ship instead of performing a task.
		/// </summary>
		int _chanceToMeander = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		/// <summary>
		/// The chance that a Killer crewmate will attempt a murder.
		/// </summary>
		int _chanceToKill = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		int _chanceToDoTask = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		/// <summary>
		/// The chance a Crewmate will forget something they've observed every "AttemptToForget" tick
		/// </summary>
		int _chanceToForget = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		/// <summary>
		///	Number of tasks given to each Innocent to perform upon starting a game.	
		/// </summary>
		int _numberOfTasksToAssign = 1;

	UPROPERTY(BlueprintReadWrite, Category = "Discussion")
		int _lastTimeSeenAlive = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Discussion")
		int _timeFrame = 20;

	UPROPERTY(BlueprintReadWrite, Category = "Discussion")
		TMap<CrewmateColorEnum, float> _suspects;

	UPROPERTY(BlueprintReadWrite, Category = "Discussion")
		AActor* _ejectionSpawnPoint = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Discussion")
		AActor* _ejectionEndPoint = nullptr;
};