// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/SphereComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("ColliderBox"));
    SphereCollider->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    Super::Tick(DeltaTime);

    FVector NewLocation = GetActorLocation();
    NewLocation += GetActorForwardVector() * Speed * DeltaTime;
    SetActorLocation(NewLocation);

    TimeLived += DeltaTime;
    if (TimeLived > TimeBeforeDestroy)
    {
        this->Destroy();
    }


}

void AProjectile::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // Check if the OtherActor is valid
    if (OtherActor && OtherActor != this)
    {
        // Print out the name of the OtherActor
        UE_LOG(LogTemp, Warning, TEXT("Projectile overlapped with actor: %s"), *OtherActor->GetName());
    }
}

