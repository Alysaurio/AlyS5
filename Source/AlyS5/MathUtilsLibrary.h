// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathUtilsLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ALYS5_API UMathUtilsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintPure, Category = "Math Utils")
    static float SumarNumeros(float A, float B);

    UFUNCTION(BlueprintPure, Category = "Math Utils")
    static FVector SumarVectores(FVector A, FVector B);

    UFUNCTION(BlueprintPure, Category = "Math Utils")
    static FVector ProductoCruz(FVector A, FVector B);

    UFUNCTION(BlueprintPure, Category = "Math Utils")
    static float DistanciaVectores(FVector A, FVector B);

};
