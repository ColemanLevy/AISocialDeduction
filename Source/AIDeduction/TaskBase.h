// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TaskBase.generated.h"

UCLASS()
class AIDEDUCTION_API ATaskBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATaskBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Goal")
		/// <summary>
		/// The description for the task.
		/// </summary>
		FString taskDescription;

	UPROPERTY(EditAnywhere, Category = "Map")
		/// <summary>
		/// The name of the room this task is in.
		/// </summary>
		FString roomName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		/// <summary>
		/// The amount of time it takes to perform this task.
		/// </summary>
		float timeToPerform;
};
