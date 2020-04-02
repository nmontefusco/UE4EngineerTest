// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_TurnRobot.h"
#include "Robot.h"
#include "RobotController.h"

UBTT_TurnRobot::UBTT_TurnRobot(const FObjectInitializer& ObjectInitializer)
{
	NodeName = "Turn Robot";
}

EBTNodeResult::Type UBTT_TurnRobot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ARobotController* RobotController = Cast<ARobotController>(OwnerComp.GetAIOwner());
	ARobot*  RobotPawn = Cast<ARobot>(RobotController->GetPawn());

	if (RobotPawn)
	{
		RobotPawn->Turn();
		return EBTNodeResult::Succeeded;
	}
	
	return EBTNodeResult::Failed;
	
}
