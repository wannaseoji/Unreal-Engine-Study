// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingFlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingFlatform : public AActor //AMoving Floatform : A는 Actor를 의미한다.
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingFlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//변수 추가
	UPROPERTY(EditAnywhere) //blueprint에서도 보이도록 설정 
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere) //blueprint에서도 보이도록 설정 
	float MyFloat = 5.99;
	UPROPERTY(EditAnywhere) //blueprint에서도 보이도록 설정 
	bool MyBool = true;
};
