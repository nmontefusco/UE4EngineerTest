// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Robot.generated.h"

UCLASS()
class AIREVERIE_CHALLENGE_API ARobot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARobot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class UStaticMeshComponent* RobotMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class UBoxComponent* RobotCollisionComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class UFloatingPawnMovement* MovementComponent;

	void TakePhoto();

	void GetAllActors();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void MoveForward();

	UFUNCTION(BlueprintCallable)
	void Turn();

	UFUNCTION(BlueprintCallable)
	void OnRobotHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(BlueprintReadWrite)
	bool bHitSomething = false;

};
