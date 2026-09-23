// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerDetector.generated.h"

UCLASS()
class ALYS5_API APlayerDetector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerDetector();
	UFUNCTION(BlueprintCallable, Category = "Deteccion")
	bool EstaJugadorALaDerecha() const;

	UFUNCTION(BlueprintCallable, Category = "Deteccion")
	bool EstaJugadorAdelante() const;

	UFUNCTION(BlueprintCallable, Category = "Deteccion")
	bool EstaJugadorEnRango(float Rango) const;

	UFUNCTION(BlueprintCallable, Category = "Deteccion")
	bool EstaJugadorEnAngulo(float AnguloGrados, float DistanciaMax) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
