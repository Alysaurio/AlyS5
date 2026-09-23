// Proyectil.cpp
#include "Proyectil.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AlyS5Character.h"

AProyectil::AProyectil()
{
	PrimaryActorTick.bCanEverTick = false;

	Colision = CreateDefaultSubobject<USphereComponent>(TEXT("Colision"));
	Colision->InitSphereRadius(15.f);
	Colision->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	Colision->SetNotifyRigidBodyCollision(true);
	RootComponent = Colision;

	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	Malla->SetupAttachment(RootComponent);
	Malla->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Movimiento = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movimiento"));
	Movimiento->InitialSpeed = 4500.f;
	Movimiento->MaxSpeed = 4500.f;
	Movimiento->ProjectileGravityScale = 0.f;
	Movimiento->bRotationFollowsVelocity = true;

	Colision->OnComponentHit.AddDynamic(this, &AProyectil::OnHit);

	InitialLifeSpan = 5.f; // se autodestruye si no choca nada en 5 seg
}

void AProyectil::BeginPlay()
{
	Super::BeginPlay();
	Movimiento->InitialSpeed = Velocidad;
	Movimiento->MaxSpeed = Velocidad;
	Movimiento->Velocity = GetActorForwardVector() * Velocidad;
}

void AProyectil::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == this) return;

	if (AAlyS5Character* Player = Cast<AAlyS5Character>(OtherActor))
	{
		Player->RestarVida(Dano);
	}
	Destroy();
}

void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}