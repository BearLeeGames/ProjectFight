// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraAdjuster.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Camera/CameraComponent.h"
#include "Engine/GameEngine.h"

// Sets default values
ACameraAdjuster::ACameraAdjuster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraAdjuster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraAdjuster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// get both player locations
	FVector PlayerOneLoc = PlayerOne->GetActorLocation();
	FVector PlayerTwoLoc = PlayerTwo->GetActorLocation();

	// get camera location
	FVector CameraLoc = Camera->GetActorLocation();

	// set x to be the midpoint
	CameraLoc.X = (PlayerOneLoc.X + PlayerTwoLoc.X) / 2;

	// set FieldOfView (or y?) to be the difference + constant * multiplier
	// constant: how far before the camera STARTS zooming out
	// multiplier: how fast the camera zooms out
	float FieldOfView = FMath::Abs(PlayerTwoLoc.X - PlayerOneLoc.X + 150) * 0.10;

	// clamp the FieldOfView, setting a min and max
	FieldOfView = FMath::Clamp(FieldOfView, 65.0f, 120.0f);

	// debugging purposes
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), FieldOfView));

	// get the camera component from camera actor inorder to set FieldOfView
	UCameraComponent* CamComp = Camera->GetCameraComponent();
	CamComp->SetFieldOfView(FieldOfView);

	// set the camera actor's new location
	Camera->SetActorLocation(CameraLoc);


}

