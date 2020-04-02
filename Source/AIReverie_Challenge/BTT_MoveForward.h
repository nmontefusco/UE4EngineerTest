// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_MoveForward.generated.h"

/**
 * 
 */
UCLASS()
class AIREVERIE_CHALLENGE_API UBTT_MoveForward : public UBTTaskNode
{
	GENERATED_BODY()
	
	UBTT_MoveForward(const FObjectInitializer& ObjectInitializer);

	//virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
