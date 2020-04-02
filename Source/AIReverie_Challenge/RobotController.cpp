// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"

ARobotController::ARobotController()
{
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoardComp"));
}

void ARobotController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (BehaviorTree)
	{
		BlackboardComp->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
		BehaviorComp->StartTree(*BehaviorTree);
	}
}

void ARobotController::OnUnPossess()
{
	Super::OnUnPossess();
	
	BehaviorComp->StopTree();
	
}
