// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Room.h"

#include "CrewMateBase.generated.h"

UENUM(BlueprintType)
/// <summary>
/// Enum which holds the colors (aka names) of all the crewmates
/// </summary>
enum class CrewmateColorEnum : uint8
{
	Red,
	Blue,
	Green,
	Yellow,
	Orange,
	Turquoise,
	Purple,
	Pink,
	Gray,
	Brown
};

USTRUCT(BlueprintType)
/// <summary>
/// The struct which holds all the information that makes up crewmate knowledge entries
/// </summary>
struct FCrewmateInformation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Knowledge")
		/// <summary>
		/// The time at which the observation was made.
		/// </summary>
		int simulationTime = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Knowledge")
		/// <summary>
		/// The color (name) of the crewmate observed
		/// </summary>
		CrewmateColorEnum crewmateName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Knowledge")
		/// <summary>
		/// The room the crewmate was seen in
		/// </summary>
		RoomEnum roomIn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Knowledge")
		/// <summary>
		/// The room the crewmate was seen leaving if applicable
		/// </summary>
		RoomEnum roomOut;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Knowledge")
		/// <summary>
		/// Bool to indicate if this knowledge is unusable in dialogue due to it being considered forgotten
		/// </summary>
		bool forgotten;
};

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

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Function that will handle what a crewmate will do when it sees another crewmate
		/// </summary>
		/// <param name="crewmate">The crewmate that was seen by this crewmate</param>
		void OnSeenCrewmateUpdate(AActor* crewmate, bool sensed);

public:	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		/// <summary>
		/// Function for turning off this crewmates perception component and perception stimuli source
		/// </summary>
		void ResetPerception();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		/// <summary>
		/// Function for turning on this crewmates perception component and perception stimuli source
		/// </summary>
		void StartPerception();

	UFUNCTION(BlueprintImplementableEvent)
		/// <summary>
		/// Function for resurrecting the crewmate and reverting it from its ghost form
		/// </summary>
		void Revive();

	UFUNCTION(BlueprintImplementableEvent)
		/// <summary>
		/// Function for being killed
		/// </summary>
		void Die();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		/// <summary>
		/// Function for initializing the task bar UI and getting a variable reference of the task bar
		/// </summary>
		void GetTaskProgressBar();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		/// <summary>
		/// Function for getting how long a task will take
		/// </summary>
		/// <param name="timeToCompleteTask">How long it will take to compelte the current task being performed by the crewmate.</param>
		void StartTask(float timeToCompleteTask);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		/// <summary>
		/// Function for reseting the task bar to 0 progress
		/// </summary>
		void ResetTaskProgress();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		/// <summary>
		/// Function to freeze a Crewmate's movements and actions.
		/// </summary>
		void Pause();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		/// <summary>
		/// Function to resume a Crewmate's movements and actions.
		/// </summary>
		void Resume();

	UFUNCTION()
		/// <summary>
		/// Function which records and sends out the information of what room this crewmate has entered
		/// </summary>
		/// <param name="newRoom">The room being entered</param>
		void EnterNewRoom(RoomEnum newRoom);

	UFUNCTION()
		/// <summary>
		/// Function for sending out movement information on this crewmates movement to all crewmates in sight
		/// </summary>
		void SendOutMovementInfo();

	UFUNCTION(BlueprintImplementableEvent)
		/// <summary>
		/// Begin the memory system loop in the Crewmate
		/// </summary>
		void InitializeMemorySystem();

	UFUNCTION(BlueprintCallable)
		/// <summary>
		/// Check if this crewmate should forget any memory. If so, go ahead and forget 2.
		/// </summary>
		void AttemptToForget();

	UFUNCTION()
		/// <summary>
		/// Function for recording crewmate information sent out by another crewmate
		/// </summary>
		/// <param name="movementInfo">The crewmate movement information being received</param>
		void ReceiveMovementInfo(const FCrewmateInformation& movementInfo);

	UFUNCTION()
		/// <summary>
		/// Function for handling what information to return when a crewmate is seen
		/// </summary>
		/// <returns>The crewmate movement information being sent out</returns>
		const FCrewmateInformation& GetSeen();

	UPROPERTY(EditAnywhere, Category = "AI")
		/// <summary>
		/// The behavior tree controlling the crewmates' actions
		/// </summary>
		class UBehaviorTree* _behaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
		/// <summary>
		/// The game mode this crewmate resides in
		/// </summary>
		class AAIDeductionGameMode* _aiDeductionGameMode;

	/// <summary>
	/// The Crewmate Controller that possesses this crewmate
	/// </summary>
	class ACrewMateController* _crewmateController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
		/// <summary>
		/// Bool to indicate to multiple sources that this crewmate is a killer.
		/// </summary>
		bool _isKiller = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Knowledge")
		/// <summary>
		/// The color (name) of the current crewmate
		/// </summary>
		CrewmateColorEnum _name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Knowledge")
		/// <summary>
		/// The roommate this crewmate is currently in. Used in display on the UI.
		/// </summary>
		RoomEnum _currentRoom;

	UPROPERTY(BlueprintReadOnly)
		/// <summary>
		/// The current movement information that this crewmate has for recording its position in the map
		/// </summary>
		FCrewmateInformation _crewmateInformation;

	UPROPERTY(BlueprintReadWrite)
		/// <summary>
		/// The list of knowledge entries that this crewmate has made from its observations
		/// </summary>
		TArray<FCrewmateInformation> _observedKnowledge;

	UPROPERTY()
		/// <summary>
		/// The number of memories that have been forgotten. Used to limit the number of memories that can be forgotten.
		/// </summary>
		int _totalForgottenMemories = 0;
};
