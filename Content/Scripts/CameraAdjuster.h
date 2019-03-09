#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraActor.h"
#include "CameraAdjuster.generated.h"

UCLASS()
class PROJECTFIGHT_API ACameraAdjuster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraAdjuster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		AActor* PlayerOne;

	UPROPERTY(EditAnywhere)
		AActor* PlayerTwo;

	UPROPERTY(EditAnywhere)
		ACameraActor* Camera;

};
