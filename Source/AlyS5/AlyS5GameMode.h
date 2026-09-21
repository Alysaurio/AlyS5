// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AlyS5GameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AAlyS5GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AAlyS5GameMode();
};



