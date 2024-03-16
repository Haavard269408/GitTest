// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USphereComponent;
class AMyCharacter;

UCLASS()
class GITHUBTEST_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// initital speed 5000, can change speed in blueprint
	UPROPERTY(EditAnywhere, Category = "Bullet")
	float Speed{ 4000.0f };

	UPROPERTY(EditAnywhere, Category = "Bullet")
	USphereComponent* SphereCollider;

	UPROPERTY(EditAnywhere)
	AMyCharacter* Character;


	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	/**Time before bullet selfdestruct*/
	UPROPERTY(EditAnywhere, Category = "Bullet")
	float TimeBeforeDestroy{ 4.f };

	float TimeLived{ 0 };


};
