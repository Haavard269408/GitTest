// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.h"
#include "SpawnManager.generated.h"

UCLASS()
class GITHUBTEST_API ASpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnManager();

	float TimeToLive;
	UPROPERTY(EditAnywhere, Category = "Spawn Setup")
	TSubclassOf<class AActor> EnemyClass;

	int EnemiesToSpawn;
	int CurrentNumOfEnemies;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int GetNumOfEnemies();

	void Spawn();



};
