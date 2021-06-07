// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CrewMateBase.generated.h"

/**
 * The class for the AI which will be playing out a game of "Among AI" for the simulation
 */
UCLASS()
class AIDEDUCTION_API ACrewMateBase : public ACharacter
{
	GENERATED_BODY()

public:
	/// <summary>
	/// Sets default values for this character's properties
	/// </summary>
	ACrewMateBase();

protected:
	/// <summary>
	/// Called when the game starts or when spawned
	/// </summary>
	virtual void BeginPlay() override;

	/// <summary>
	/// Function that will handle what a crewmate will do when it sees another crewmate
	/// </summary>
	/// <param name="crewmate">The crewmate that was seen by this crewmate</param>
	void OnCrewmateSeen(APawn* crewmate);

public:	
	UPROPERTY(EditAnywhere, Category = "AI")
		/// <summary>
		/// The behavior tree controlling the crewmates' actions
		/// </summary>
		class UBehaviorTree* behaviorTree;

	UPROPERTY(VisibleAnywhere, Category = "AI")
		/// <summary>
		/// The component which will handle the sight sense for the crewmates
		/// </summary>
		class UAIPerceptionComponent* perceptionComp;

	UPROPERTY(VisibleAnywhere, Category = "References")
		/// <summary>
		/// The game mode this crewmate resides in
		/// </summary>
		class AAIDeductionGameMode* aiDeductionGameMode;
};
