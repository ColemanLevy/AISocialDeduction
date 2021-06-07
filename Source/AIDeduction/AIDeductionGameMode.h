// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CrewMateBase.h"

#include "AIDeductionGameMode.generated.h"

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
		/// Function to indicate to all crewmatesa and the player spectator that the simulation has begun.
		/// </summary>
		void StartGame();
	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function to return all of the crewmates and the player camera to their initial positions, and wipe all of the crewmates memories.
		/// </summary>
		void ResetGame();

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Sets the reference to the PlayerSpectator for the game mode.
		/// </summary>
		/// <param name="newPlayerCamera">The new PlayerSpectator to refer to.</param>
		void SetPlayerSpectator(APlayerSpectator* newPlayerCamera);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Map")
		/// <summary>
		/// The list of all waypoints in the simulation.
		/// </summary>
		TArray<AActor*> wayPoints;
	UPROPERTY(EditAnywhere, Category = "Map")
		/// <summary>
		/// The class of what the waypoints are. This is set in the game mode's blueprint and indicates to what the 
		/// game mode should be looking for when filling the list of waypoint references.
		/// </summary>
		TSubclassOf<AActor> wayPointsClass;

	/// <summary>
	/// Reference to the main menu screen UI.
	/// </summary>
	UUserWidget* mainMenu;

	UPROPERTY(EditAnywhere, Category = "UI")
		/// <summary>
		/// The class type of the main menu, used to indicate what type of UI should be created for the main menu.
		/// </summary>
		TSubclassOf<UUserWidget> mainMenuClass;

	UPROPERTY(EditAnywhere, Category = "AI")
		/// <summary>
		/// List of all the crewmates in the game.
		/// </summary>
		TArray<ACrewMateBase*> crewMates;

	/// <summary>
	/// Reference to the PlayerSpectator, which is the pawn the player has control of in the game.
	/// </summary>
	class APlayerSpectator* playerSpectator;

	/// <summary>
	/// Boolean to indicate a round of the simulation is in session.
	/// </summary>
	bool gameStarted = false;
};