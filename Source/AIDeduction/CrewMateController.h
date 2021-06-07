// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
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
	/// Getter for the Blackboard component
	/// </summary>
	/// <returns>The blackboard component attach to this crewmate controller.</returns>
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return blackboardComp; }

	UPROPERTY(VisibleAnywhere, Category = "AI")
		/// <summary>
		/// The behavior tree this crewmate is controlled by.
		/// </summary>
		class UBehaviorTreeComponent* behaviorComp;

	UPROPERTY(VisibleAnywhere, Category = "AI")
		/// <summary>
		/// The blackboard component attached to this crewmate.
		/// </summary>
		class UBlackboardComponent* blackboardComp;

	UPROPERTY(EditAnywhere, Category = "AI")
		/// <summary>
		/// The crewmate this controller is possessing
		/// </summary>
		class ACrewMateBase* crewmateNPC;

	UPROPERTY(EditAnywhere, Category = "AI")
		/// <summary>
		/// The initial transform of the crewmate this controller is possessing.
		/// </summary>
		FTransform startingTransform;

	UPROPERTY(EditAnywhere, Category = "References")
		/// <summary>
		/// The gamemode this controller resides in.
		/// </summary>
		class AAIDeductionGameMode* gameMode;
};
