// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	movementSpeed = 1.f;

	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}


void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//returns true if is server
	if (HasAuthority())
	{
		FVector location = GetActorLocation();
		location += FVector(movementSpeed * DeltaTime, 0.f, 0.f);
		SetActorLocation(location);
	}
}
