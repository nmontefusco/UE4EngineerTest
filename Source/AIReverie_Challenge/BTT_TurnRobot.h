// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_TurnRobot.generated.h"

/*
   Calls the Turn logic declared in  ARobot::Turn()
 */
UCLASS()
class AIREVERIE_CHALLENGE_API UBTT_TurnRobot : public UBTTaskNode
{
	GENERATED_BODY()
	
	UBTT_TurnRobot(const FObjectInitializer& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
