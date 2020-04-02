// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_UpdateRoboHit.h"
#include "Robot.h"
#include "RobotController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTS_UpdateRoboHit::UBTS_UpdateRoboHit(const FObjectInitializer & ObjectInitializer):Super(ObjectInitializer)
{
	NodeName = "Update Robot Hit";

	bNotifyBecomeRelevant = true;
	bNotifyCeaseRelevant = false;
	bHitSomething.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UBTS_UpdateRoboHit, bHitSomething));
}

void UBTS_UpdateRoboHit::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == NULL)
	{
		return;
	}

	ARobotController* RobotController = Cast<ARobotController>(OwnerComp.GetAIOwner());
	ARobot*  RobotPawn = Cast<ARobot>(RobotController->GetPawn());

	if (RobotPawn->bHitSomething == true)
	{
		BlackboardComp->SetValueAsBool(bHitSomething.SelectedKeyName, true);
	}
	else
	{
		BlackboardComp->SetValueAsBool(bHitSomething.SelectedKeyName, false);
	}
	
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

FString UBTS_UpdateRoboHit::GetStaticDescription() const
{
	return FString::Printf(TEXT("%s: '%s'"), TEXT("Robot Hit Something?"), bHitSomething.IsSet() ? *bHitSomething.SelectedKeyName.ToString() : TEXT(""));
}

void UBTS_UpdateRoboHit::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == NULL)
	{
		return;
	}
}
