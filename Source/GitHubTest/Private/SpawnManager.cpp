// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemiesToSpawn = 5;
	CurrentNumOfEnemies = 0;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	while (CurrentNumOfEnemies <= EnemiesToSpawn) {
		Spawn();
	}

}

int ASpawnManager::GetNumOfEnemies()
{
	return CurrentNumOfEnemies;
}

void ASpawnManager::Spawn()
{
	float SpawnX = FMath::RandRange(-3000.f, 3000.0f);
	float SpawnY = FMath::RandRange(-3000.f, 2000.f);
	float SpawnZ = 1.0f; // Spawn above the ground

	FVector SpawnPosition = FVector(SpawnX, SpawnY, SpawnZ);

	GetWorld()->SpawnActor<AActor>(EnemyClass, SpawnPosition, FRotator::ZeroRotator);
	
	CurrentNumOfEnemies++;

}

