// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MoveForward.h"
#include "Robot.h"
#include "RobotController.h"

UBTT_MoveForward::UBTT_MoveForward(const FObjectInitializer& ObjectInitializer)
{
	NodeName = "Move Forward";
	bNotifyTick = true;
}

/*
void UBTT_MoveForward::TickTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	
}
*/


EBTNodeResult::Type UBTT_MoveForward::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ARobotController* RobotController = Cast<ARobotController>(OwnerComp.GetAIOwner());
	ARobot*  RobotPawn = Cast<ARobot>(RobotController->GetPawn());

	if (RobotPawn)
	{
		RobotPawn->MoveForward();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}

