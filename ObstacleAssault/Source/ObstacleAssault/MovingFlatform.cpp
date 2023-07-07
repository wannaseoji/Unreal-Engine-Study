// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingFlatform.h"

// Sets default values
AMovingFlatform::AMovingFlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingFlatform::BeginPlay()
{
	Super::BeginPlay();
	// BeginPlay 다음에 게임플레이를 시작할 때 바로 실행될 코드
	// Unity 의 Start와 같은 역할
	// Header에서 선언했던 변수들을 접근하고 초기화 할 수 있다.
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingFlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation+(PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if(DistanceMoved > MoveDistance)
	{
		PlatformVelocity = -PlatformVelocity;
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
	}

}

