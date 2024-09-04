// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEffect.generated.h"

UCLASS()
class SGA_TEAM_YPK_API AMyEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMyEffect();

	virtual void Tick(float DeltaTime) override;

	void Play(FVector location, FRotator rotator);

	bool IsPlaying();

	UFUNCTION()
	void End(class UParticleSystemComponent* particle);

	UFUNCTION()
	void EndSystem(class UParticleSystem* particle);

protected:
	
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* _particleCom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* _particleSceneCom;

};
