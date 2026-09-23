// Item.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class ALYS5_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();

	UPROPERTY(EditAnywhere, Category = "Item")
	float Cantidad = 20.f;

	UPROPERTY(EditAnywhere, Category = "Item")
	bool bResta = false; // false = suma vida, true = resta vida

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Colision;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	virtual void Tick(float DeltaTime) override;
};