// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TaskBase.h"
#include "CrewMateBase.h"

#include "CrewMateController.generated.h"

/**
 * The controller for the crewmates which determine how they will act.
 */
UCLASS()
class AIDEDUCTION_API ACrewMateController : public AAIController
{
	GENERATED_BODY()

private:
	/// <summary>
	/// Called when the game starts or when spawned
	/// </summary>
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		/// <summary>
		/// The blackboard key which defines where the AI should be moving to.
		/// </summary>
		FName LocationToGoKey;

public:
	/// <summary>
	/// onstructor for the class
	/// </summary>
	ACrewMateController();

	/// <summary>
	/// Function which is performed when the contorller possesses a pawn in the scene.
	/// </summary>
	/// <param name="pawn">The pawn that was possessed</param>
	void OnPossess(APawn* pawn) override;

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function to start the crewmate's behavior tree.
		/// </summary>
		void StartAI();
	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function to reset a crewmate to where it spawned, clear its memories, and stop its behavior tree
		/// </summary>
		void ResetAI();

	/// <summary>
	/// Function which handles what occurs when a Killer kills the Crewmate this controller manages.
	/// </summary>
	void GetKilled();

	/// <summary>
	/// Grabs the next task for this Crewmate to perform out of its randomly assigned tasks.
	/// </summary>
	/// <returns>Returns the task to move to on the map.</returns>
	AActor* GetNextUnfinishedTask();
	/// <summary>
	/// Function that occurs when a Crewmate "completes" a task. Handles incrementing the number of tasks this Crewmate has completed.
	/// </summary>
	void TaskCompleted();

	/// <summary>
	/// Handles adding the seen Crewmate to the list of Crewmates in sight. 
	/// </summary>
	/// <param name="crewmate">The seen Crewmate.</param>
	void CrewmateSeen(ACrewMateBase* crewmate);
	/// <summary>
	/// Handles removing the Crewmate that just left vision from the list of Crewmates in sight.
	/// </summary>
	/// <param name="crewmate">The Crewmatet that just left vision.</param>
	void CrewmateUnseen(ACrewMateBase* crewmate);

	/// <summary>
	/// Getter for the Blackboard component
	/// </summary>
	/// <returns>The blackboard component attach to this crewmate controller.</returns>
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return _blackboardComp; }

	UPROPERTY(VisibleAnywhere, Category = "AI")
		/// <summary>
		/// The behavior tree this crewmate is controlled by.
		/// </summary>
		class UBehaviorTreeComponent* _behaviorComp;

	UPROPERTY(VisibleAnywhere, Category = "AI")
		/// <summary>
		/// The blackboard component attached to this crewmate.
		/// </summary>
		class UBlackboardComponent* _blackboardComp;

	UPROPERTY(EditAnywhere, Category = "AI")
		/// <summary>
		/// The crewmate this controller is possessing
		/// </summary>
		class ACrewMateBase* _crewmateNPC;

	UPROPERTY(EditAnywhere, Category = "AI")
		/// <summary>
		/// The initial transform of the crewmate this controller is possessing.
		/// </summary>
		FTransform _startingTransform;

	UPROPERTY(EditAnywhere, Category = "References")
		/// <summary>
		/// The gamemode this controller resides in.
		/// </summary>
		class AAIDeductionGameMode* _aiDeductionGameMode;

	UPROPERTY(EditAnywhere, Category = "AI")
		/// <summary>
		/// The list of tasks to perform.
		/// </summary>
		TArray<ATaskBase*> _tasks;

	/// <summary>
	/// The list of Crewmates this Crewmate can currently see.
	/// </summary>
	TArray<ACrewMateBase*> _crewmatesInSight;

	/// <summary>
	/// The number of tasks this Crewmate has completed.
	/// </summary>
	int _numberOfCompletedTasks = 0;
};
