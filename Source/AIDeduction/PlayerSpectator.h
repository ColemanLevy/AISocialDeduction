// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIDeductionGameMode.h"

#include "PlayerSpectator.generated.h"

/**
* The pawn the player controls when spectating the simulation.
*/
UCLASS()
class AIDEDUCTION_API APlayerSpectator : public ACharacter
{
	GENERATED_BODY()

public:
	/// <summary>
	/// Sets default values for this character's properties
	/// </summary>
	APlayerSpectator();

protected:
	/// <summary>
	/// Called when the game starts or when spawned
	/// </summary>
	virtual void BeginPlay() override;

	/// <summary>
	/// Function for moving the player towards or away from where they are facing.
	/// </summary>
	/// <param name="distance">The amount to move by.</param>
	void MoveForward(float distance);
	/// <summary>
	/// Function for moving the player to the left or right of where they are facing.
	/// </summary>
	/// <param name="distance">The amount to move by.</param>
	void MoveRight(float distance);
	/// <summary>
	/// Function to turn the player's camera up or down.
	/// </summary>
	/// <param name="radians">The amount to turn by.</param>
	void TurnUp(float radians);
	/// <summary>
	/// Function to turn the player's camera left or right.
	/// </summary>
	/// <param name="radians">The amount to turn by.</param>
	void TurnRight(float radians);

	/// <summary>
	/// Function to activate "TurnMode", which hides the player's mouse and allows for the camera to turn.
	/// </summary>
	void TurnModeOn();

	/// <summary>
	/// Boolean which indicates if TurnMode is on or not.
	/// </summary>
	bool turnMode = false;

public:	
	/// <summary>
	/// Called every frame
	/// </summary>
	/// <param name="DeltaTime">The amount of time that has passed since the last call to this function.</param>
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// Called to bind functionality to input
	/// </summary>
	/// <param name="PlayerInputComponent"></param>
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/// <summary>
	/// Function which brings the camera back to its initial transfrom in the map. Used on re-entering the main menu.
	/// </summary>
	void ResetTransform();

	/// <summary>
	/// Function to deactivate "TurnMode", which will cause the mouse to be revealed and stop allowing the player's camera to move.
	/// </summary>
	void TurnModeOff();

	/// <summary>
	/// Reference to the GameMode this PlayerSpectator resides in.
	/// </summary>
	AAIDeductionGameMode* aiDeductionGameMode;
	/// <summary>
	/// Reference to the controller of the PlayerSpectator.
	/// </summary>
	APlayerController* controller;
	/// <summary>
	/// Reference to the component which handles input from the player.
	/// </summary>
	UInputComponent* inputComponent;

	/// <summary>
	/// Transform used for resetting the camera's position to where it initial spawned.
	/// </summary>
	FTransform startingTransform;

	/// <summary>
	/// Struct for holding the position of the player's mouse on the screen.
	/// </summary>
	struct MousePosition
	{
		float x = 0;
		float y = 0;
	} mousePosition;
};
