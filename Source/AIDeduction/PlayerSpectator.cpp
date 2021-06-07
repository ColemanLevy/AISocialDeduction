// ---------------------------------------------------------------------
// Name: Coleman Levy
// Date: 6/3/21
// Description: Class for the player to control in the simulation. Acts similar to the camera
//				in the Unreal editor when it comes to movement.
// ---------------------------------------------------------------------

#include "PlayerSpectator.h"

// Sets default values
APlayerSpectator::APlayerSpectator()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerSpectator::BeginPlay()
{
	Super::BeginPlay();

	// Grabbing the AIDeductionGameMode for access to its values and to give it the reference to this PlayerSpectator. Akso
	// initializes the input for calling to the ResetGame function.
	aiDeductionGameMode = Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode());
	aiDeductionGameMode->SetPlayerSpectator(this);
	inputComponent->BindAction("MainMenuDebug", IE_Pressed, aiDeductionGameMode, &AAIDeductionGameMode::ResetGame);

	controller = Cast<APlayerController>(GetController());
	controller->bShowMouseCursor = true; // Start the game with the mouse cursor showing

	startingTransform = GetTransform();
}

// Function for moving the player towards/away from where they're facing.
void APlayerSpectator::MoveForward(float distance)
{
	// Only move the player if the simulation has begun
	if ((Controller) && (distance != 0.0f) && aiDeductionGameMode->gameStarted)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, distance);
	}
}

// Function for moving the player left/right
void APlayerSpectator::MoveRight(float distance)
{
	// Only move the player if the simulation has begun
	if ((Controller) && (distance != 0.0f) && aiDeductionGameMode->gameStarted)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, distance);
	}
}

// Function for turning the player up/down
void APlayerSpectator::TurnUp(float radians)
{
	// Ony perform the turning if the TurnMode is on and the simulation has begun
	if (turnMode)
	{
		if ((Controller) && (radians != 0.0f) && aiDeductionGameMode->gameStarted)
		{
			AddControllerPitchInput(radians);
		}
	}
}

// Function for turning the player left/right
void APlayerSpectator::TurnRight(float radians)
{
	// Ony perform the turning if the TurnMode is on and the simulation has begun
	if (turnMode)
	{
		if ((Controller) && (radians != 0.0f) && aiDeductionGameMode->gameStarted)
		{
			AddControllerYawInput(radians);
		}
	}
}

// Turns on TurnMode, which allows for turning of the player camera
void APlayerSpectator::TurnModeOn()
{
	if (controller && aiDeductionGameMode->gameStarted)
	{
		// Hides the mouse during the turning of the camera and sets its position to be locked at
		turnMode = true;
		controller->bShowMouseCursor = false;
		controller->bEnableMouseOverEvents = false;

		controller->GetMousePosition(mousePosition.x, mousePosition.y);
	}
}

// Turns off TurnMode, which stops turning of the player camera
void APlayerSpectator::TurnModeOff()
{
	if (controller)
	{
		turnMode = false;
		controller->bShowMouseCursor = true;
		controller->bEnableMouseOverEvents = true;
	}
}

// Called every frame
void APlayerSpectator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Prevents the mouse cursor from moving when the player is turning the camera to prevent disorientation of the player
	// as to the position of the mouse on the moving is over.
	if (turnMode)
	{
		controller->SetMouseLocation(mousePosition.x, mousePosition.y);
	}
}

// Called to bind functionality to input
void APlayerSpectator::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	inputComponent = PlayerInputComponent;

	// Binding of all the turning and moving functions of the PlayerSpectator to the player's input
	inputComponent->BindAxis("MoveForward", this, &APlayerSpectator::MoveForward);
	inputComponent->BindAxis("MoveRight", this, &APlayerSpectator::MoveRight);
	inputComponent->BindAxis("TurnUp", this, &APlayerSpectator::TurnUp);
	inputComponent->BindAxis("TurnRight", this, &APlayerSpectator::TurnRight);
	inputComponent->BindAction("MouseRightButton", IE_Pressed, this, &APlayerSpectator::TurnModeOn);
	inputComponent->BindAction("MouseRightButton", IE_Released, this, &APlayerSpectator::TurnModeOff);
}

// Function for returning the player's camera back to it initial position. Mostly used for entering the
// main menu.
void APlayerSpectator::ResetTransform()
{
	SetActorTransform(startingTransform);
}