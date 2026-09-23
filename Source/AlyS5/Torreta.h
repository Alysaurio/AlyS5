// Torreta.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Torreta.generated.h"

class AProyectil;

UCLASS()
class ALYS5_API ATorreta : public AActor
{
	GENERATED_BODY()

public:
	ATorreta();

	UPROPERTY(EditAnywhere, Category = "Torreta")
	TSubclassOf<AProyectil> ClaseProyectil;

	UPROPERTY(EditAnywhere, Category = "Torreta")
	float AnguloVision = 60.f;

	UPROPERTY(EditAnywhere, Category = "Torreta")
	float DistanciaVision = 1500.f;

	UPROPERTY(EditAnywhere, Category = "Torreta")
	float Cadencia = 2.f;

	UPROPERTY(EditAnywhere, Category = "Torreta")
	float VelocidadRotacion = 5.f;

protected:
	virtual void BeginPlay() override;

	FRotator RotacionInicial;

	FTimerHandle TimerDisparo;
	void IntentarDisparar();

public:
	virtual void Tick(float DeltaTime) override;
};