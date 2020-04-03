// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "RobotController.generated.h"

/**
   The A.I Controller for our Robot Pawn
 */
UCLASS()
class AIREVERIE_CHALLENGE_API ARobotController : public AAIController
{
	GENERATED_BODY()

	ARobotController();

	void OnPossess(APawn* InPawn) override;

	void OnUnPossess() override;

public:

	FORCEINLINE class UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }

	FORCEINLINE class UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

private:

	UBehaviorTreeComponent* BehaviorComp;

	UBlackboardComponent* BlackboardComp;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* BehaviorTree;

};
