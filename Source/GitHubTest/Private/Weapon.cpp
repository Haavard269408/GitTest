// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "MyCharacter.h"
#include "Engine.h" 
#include "Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision box"));
	SetRootComponent(CollisionSphere);
	 
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	WeaponMesh->SetupAttachment(GetRootComponent());

	

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnSphereOverlap);

}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	
	AMyCharacter* playerCharacter = Cast<AMyCharacter>(OtherActor);

	if (playerCharacter) {

		FString Message = FString::Printf(TEXT("Actor name: %s"), *playerCharacter->GetName());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Message);

		Destroy();

		playerCharacter->SetWeaponHidden();
		
	}


}

void AWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

