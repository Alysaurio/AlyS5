// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDetector.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerDetector::APlayerDetector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerDetector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerDetector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

static AActor* GetPlayer(const UWorld* World)
{
    return UGameplayStatics::GetPlayerPawn(World, 0);
}

bool APlayerDetector::EstaJugadorALaDerecha() const
{
    AActor* P = GetPlayer(GetWorld());
    if (!P) return false;
    FVector Dir = (P->GetActorLocation() - GetActorLocation()).GetSafeNormal();
    return FVector::DotProduct(Dir, GetActorRightVector()) > 0.f;
}

bool APlayerDetector::EstaJugadorAdelante() const
{
    AActor* P = GetPlayer(GetWorld());
    if (!P) return false;
    FVector Dir = (P->GetActorLocation() - GetActorLocation()).GetSafeNormal();
    return FVector::DotProduct(Dir, GetActorForwardVector()) > 0.f;
}

bool APlayerDetector::EstaJugadorEnRango(float Rango) const
{
    AActor* P = GetPlayer(GetWorld());
    return P && FVector::Dist(GetActorLocation(), P->GetActorLocation()) <= Rango;
}

bool APlayerDetector::EstaJugadorEnAngulo(float AnguloGrados, float DistanciaMax) const
{
    AActor* P = GetPlayer(GetWorld());
    if (!P) return false;
    if (FVector::Dist(GetActorLocation(), P->GetActorLocation()) > DistanciaMax) return false;
    FVector Dir = (P->GetActorLocation() - GetActorLocation()).GetSafeNormal();
    float Angulo = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(GetActorForwardVector(), Dir)));
    return Angulo <= AnguloGrados * 0.5f;
}