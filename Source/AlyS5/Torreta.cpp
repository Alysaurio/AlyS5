// Torreta.cpp
#include "Torreta.h"
#include "Proyectil.h"
#include "Kismet/GameplayStatics.h"

ATorreta::ATorreta()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATorreta::BeginPlay()
{
	Super::BeginPlay();
	RotacionInicial = GetActorRotation();
	GetWorldTimerManager().SetTimer(TimerDisparo, this, &ATorreta::IntentarDisparar, Cadencia, true);
}

void ATorreta::IntentarDisparar()
{
	AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player || !ClaseProyectil) return;

	if (FVector::Dist(GetActorLocation(), Player->GetActorLocation()) > DistanciaVision) return;

	FVector Dir = (Player->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	float Angulo = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(GetActorForwardVector(), Dir)));
	if (Angulo > AnguloVision * 0.5f) return;

	FVector SpawnLoc = GetActorLocation() + Dir * 100.f;
	GetWorld()->SpawnActor<AProyectil>(ClaseProyectil, SpawnLoc, Dir.Rotation());
}

void ATorreta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) return;

	FVector Dir = Player->GetActorLocation() - GetActorLocation();
	FVector DirNorm = Dir.GetSafeNormal();

	FVector ForwardInicial = RotacionInicial.Vector();
	float Angulo = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(ForwardInicial, DirNorm)));

	FRotator RotObjetivo = (Angulo <= AnguloVision * 0.5f) ? Dir.Rotation() : RotacionInicial;
	FRotator NuevaRot = FMath::RInterpTo(GetActorRotation(), RotObjetivo, DeltaTime, VelocidadRotacion);
	SetActorRotation(NuevaRot);
}