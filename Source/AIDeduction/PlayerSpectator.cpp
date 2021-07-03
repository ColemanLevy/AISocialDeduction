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
	_aiDeductionGameMode = Cast<AAIDeductionGameMode>(GetWorld()->GetAuthGameMode());
	_aiDeductionGameMode->SetPlayerSpectator(this);
	_inputComponent->BindAction("MainMenuDebug", IE_Pressed, _aiDeductionGameMode, &AAIDeductionGameMode::ResetGame);
	_inputComponent->BindAction("ShowHideKnowledge", IE_Pressed, _aiDeductionGameMode, &AAIDeductionGameMode::ShowHideKnowledge);
	_inputComponent->BindAction("PauseAI", IE_Pressed, _aiDeductionGameMode, &AAIDeductionGameMode::PauseButton);
	_inputComponent->BindAxis("Wheel", _aiDeductionGameMode, &AAIDeductionGameMode::ScrollKnowledgeList);
	_inputComponent->BindAction("NextCrewmate", IE_Pressed, _aiDeductionGameMode, &AAIDeductionGameMode::ObserveNextCrewmate);
	_inputComponent->BindAction("PreviousCrewmate", IE_Pressed, _aiDeductionGameMode, &AAIDeductionGameMode::ObservePreviousCrewmate);

	_controller = Cast<APlayerController>(GetController());
	_controller->bShowMouseCursor = true; // Start the game with the mouse cursor showing

	_startingTransform = GetTransform();
}

// Function for moving the player towards/away from where they're facing.
void APlayerSpectator::MoveForward(float distance)
{
	// Only move the player if the simulation has begun
	if ((Controller) && (distance != 0.0f) && _aiDeductionGameMode->_gameStarted)
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
	if ((Controller) && (distance != 0.0f) && _aiDeductionGameMode->_gameStarted)
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
	if (_turnMode)
	{
		if ((Controller) && (radians != 0.0f) && _aiDeductionGameMode->_gameStarted)
		{
			AddControllerPitchInput(radians);
		}
	}
}

// Function for turning the player left/right
void APlayerSpectator::TurnRight(float radians)
{
	// Ony perform the turning if the TurnMode is on and the simulation has begun
	if (_turnMode)
	{
		if ((Controller) && (radians != 0.0f) && _aiDeductionGameMode->_gameStarted)
		{
			AddControllerYawInput(radians);
		}
	}
}

// Turns on TurnMode, which allows for turning of the player camera
void APlayerSpectator::TurnModeOn()
{
	if (_controller && _aiDeductionGameMode->_gameStarted)
	{
		// Hides the mouse during the turning of the camera and sets its position to be locked at
		_turnMode = true;
		_controller->bShowMouseCursor = false;
		_controller->bEnableMouseOverEvents = false;

		_controller->GetMousePosition(_mousePosition.x, _mousePosition.y);
	}
}

// Turns off TurnMode, which stops turning of the player camera
void APlayerSpectator::TurnModeOff()
{
	if (_controller)
	{
		_turnMode = false;
		_controller->bShowMouseCursor = true;
		_controller->bEnableMouseOverEvents = true;
	}
}

// Called every frame
void APlayerSpectator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Prevents the mouse cursor from moving when the player is turning the camera to prevent disorientation of the player
	// as to the position of the mouse on the moving is over.
	if (_turnMode)
	{
		_controller->SetMouseLocation(_mousePosition.x, _mousePosition.y);
	}
}

// Called to bind functionality to input
void APlayerSpectator::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	_inputComponent = PlayerInputComponent;

	// Binding of all the turning and moving functions of the PlayerSpectator to the player's input
	_inputComponent->BindAxis("MoveForward", this, &APlayerSpectator::MoveForward);
	_inputComponent->BindAxis("MoveRight", this, &APlayerSpectator::MoveRight);
	_inputComponent->BindAxis("TurnUp", this, &APlayerSpectator::TurnUp);
	_inputComponent->BindAxis("TurnRight", this, &APlayerSpectator::TurnRight);
	_inputComponent->BindAction("MouseRightButton", IE_Pressed, this, &APlayerSpectator::TurnModeOn);
	_inputComponent->BindAction("MouseRightButton", IE_Released, this, &APlayerSpectator::TurnModeOff);
}

// Function for returning the player's camera back to it initial position. Mostly used for entering the
// main menu.
void APlayerSpectator::ResetTransform()
{
	_controller->SetControlRotation(FRotator(0.0f, 179.9f, 0.0f));
	SetActorTransform(_startingTransform);
}