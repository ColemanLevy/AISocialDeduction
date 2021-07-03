// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrewmateBase.h"

#include "DeadCrewmate.generated.h"

UCLASS()
class AIDEDUCTION_API ADeadCrewmate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeadCrewmate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Initialize(CrewmateColorEnum inputColor, FCrewmateInformation inputInformation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void GetSeen();

	UPROPERTY(BlueprintReadWrite, Category = "Color")
		CrewmateColorEnum color;

	UPROPERTY(BlueprintReadWrite, Category = "Knowledge")
		FCrewmateInformation deathInformation;
};
