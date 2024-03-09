// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TimeToLive = 5.0f;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();

	float SpawnX = FMath::RandRange(0.0f, 1000.0f);
	float SpawnY = FMath::RandRange(0.f, 0.f);

	float SpawnZ = 1.0f; // Spawn above the ground
	FVector SpawnPosition = FVector(SpawnX, SpawnY, SpawnZ);

	GetWorld()->SpawnActor<AWeapon>(WeaponClass, SpawnPosition, FRotator::ZeroRotator);
	
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);





}

