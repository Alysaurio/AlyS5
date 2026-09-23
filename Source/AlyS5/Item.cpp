// Item.cpp
#include "Item.h"
#include "Components/SphereComponent.h"
#include "AlyS5Character.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = false;

	Colision = CreateDefaultSubobject<USphereComponent>(TEXT("Colision"));
	Colision->InitSphereRadius(50.f);
	Colision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = Colision;

	Colision->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlap);
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
}

void AItem::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AAlyS5Character* Player = Cast<AAlyS5Character>(OtherActor))
	{
		bResta ? Player->RestarVida(Cantidad) : Player->AgregarVida(Cantidad);
		Destroy();
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}