// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.generated.h"

UENUM(BlueprintType)
/// <summary>
/// Enum that holds each type of room in the simulation.
/// </summary>
enum class RoomEnum : uint8
{
	None,
	Cafeteria,
	Storage,
	Bridge,
	Shields,
	Guns,
	LHall,
	RHall,
	Lounge,
	Mapping,
	Engine,
	Medbay,
	Greenhouse
};

UCLASS()
class AIDEDUCTION_API ARoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/// <summary>
	/// The collision box that this Room uses to check for when a Crewmate enters a room.
	/// </summary>
	class UBoxComponent* _collisionBox;

	UFUNCTION()
		/// <summary>
		/// Function provided by Unreal when an Actor overlaps with this collision area.
		/// </summary>
		void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// The name of the room this collision box resides over.
	UPROPERTY(EditAnywhere, Category = "Map")
		RoomEnum _roomName;
};
