// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation= CurrentLocation+Speed*DeltaTime;
	SetActorLocation(CurrentLocation);

	float Distance = FVector::Dist(CurrentLocation, StartLocation);

	if (Distance > MaxDistance)
	{
		const FVector SpeedNormal = Speed.GetSafeNormal();
		StartLocation = StartLocation + MaxDistance * SpeedNormal;
		SetActorLocation(StartLocation);
		Speed = -Speed;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	
	AddActorLocalRotation(RotationSpeed*DeltaTime);
	
}


