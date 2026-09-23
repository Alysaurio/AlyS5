// Proyectil.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Proyectil.generated.h"

UCLASS()
class ALYS5_API AProyectil : public AActor
{
	GENERATED_BODY()

public:
	AProyectil();

	UPROPERTY(EditAnywhere, Category = "Proyectil")
	float Dano = 10.f;
	UPROPERTY(EditAnywhere, Category = "Proyectil")
	float Velocidad = 1500.f;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere) class USphereComponent* Colision;
	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* Malla;
	UPROPERTY(VisibleAnywhere) class UProjectileMovementComponent* Movimiento;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);

public:
	virtual void Tick(float DeltaTime) override;
};