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

	AAIController* AIController = OwnerComp.GetAIOwner();
	ARobotController* RobotController = Cast<ARobotController>(AIController);
	ARobot*  RobotPawn = Cast<ARobot>(RobotController->GetPawn());

	//Set the Blackboard key value to our  Robot Pawn's bHitSomething value
	BlackboardComp->SetValueAsBool(bHitSomething.SelectedKeyName, RobotPawn->bHitSomething);

	
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
