// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEffectManager.generated.h"

class AMyEffect;

UCLASS()
class SGA_TEAM_YPK_API AMyEffectManager : public AActor
{
	GENERATED_BODY()
	
public:	
	void CreateParticleClass(FString name, FString path);

	AMyEffectManager();
		
	void CreateEffect();

	void Play(FString name, FVector location, FRotator rotator = FRotator::ZeroRotator);

protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	
	int32 _poolCount = 5;
	
	UPROPERTY()
	TMap<FString, TSubclassOf<AMyEffect>> _classTable;
		
	TMap<FString, TArray<AMyEffect*>> _effectTable;
	
	UPROPERTY()
	class USceneComponent* _rootComponent;

	
};
