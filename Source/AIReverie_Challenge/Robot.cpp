// Fill out your copyright notice in the Description page of Project Settings.


#include "Robot.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARobot::ARobot()
{
 	
	RobotCollisionComp = CreateDefaultSubobject <UBoxComponent>(TEXT("RobotCollisonComp"));
	RobotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RobotMesh"));

	RootComponent = RobotCollisionComp;
	RobotMesh->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("RobotMovementComponent"));
}

// Called when the game starts or when spawned
void ARobot::BeginPlay()
{
	Super::BeginPlay();
	
	RobotCollisionComp->OnComponentHit.AddDynamic(this, &ARobot::OnRobotHit);
	TakePhoto();
}

void ARobot::TakePhoto()
{
	// Generate a filename based on the current date
	const FDateTime Now = FDateTime::Now();

	// store screenshot in Project directory next to main UProject/EXE based on the build type
#if WITH_EDITOR
	const FString ImageDirectory = FString::Printf(TEXT("%s/%s"), *FPaths::ProjectDir(), TEXT("Screenshots"));
#else
	const FString ImageDirectory = FString::Printf(TEXT("%s/../%s"), *FPaths::ProjectDir(), TEXT("Screenshots"));
#endif

	const FString ImageFilename = FString::Printf(TEXT("%s/Screenshot_%d%02d%02d_%02d%02d%02d_%03d.png"), *ImageDirectory, Now.GetYear(), Now.GetMonth(), Now.GetDay(), Now.GetHour(), Now.GetMinute(), Now.GetSecond(), Now.GetMillisecond());

	FScreenshotRequest::RequestScreenshot(ImageFilename, false, false);
}

void ARobot::GetAllActors()
{
	//TArray<AActor> ActorArray;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor, ActorArray);
}

void ARobot::MoveForward()
{
	FVector ForwardVector = GetActorForwardVector();
	AddMovementInput(ForwardVector,1.f);
}


void ARobot::Turn()
{
	bHitSomething = false;
	MovementComponent->StopMovementImmediately();
	float RandomRoll = FMath::RandRange(-5.f, 25.f);
	FRotator RoboRotation = GetActorRotation() + (FRotator(0.f, RandomRoll, 0.0f));

	SetActorRotation(RoboRotation);
}

void ARobot::OnRobotHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	bHitSomething = true;
}

// Called every frame
void ARobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

