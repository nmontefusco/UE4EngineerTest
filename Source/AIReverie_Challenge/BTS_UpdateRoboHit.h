// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_UpdateRoboHit.generated.h"

UCLASS()
class AIREVERIE_CHALLENGE_API UBTS_UpdateRoboHit : public UBTService
{
	GENERATED_BODY()

		UBTS_UpdateRoboHit(const FObjectInitializer & ObjectInitializer);

public:
	
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector bHitSomething;

private:
	bool bServiceHitPlayer;

protected:

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	virtual FString GetStaticDescription() const override;

	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
