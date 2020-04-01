// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "AIReverie_ChallengeGameMode.h"
#include "AIReverie_ChallengePlayerController.h"
#include "AIReverie_ChallengeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAIReverie_ChallengeGameMode::AAIReverie_ChallengeGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAIReverie_ChallengePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}