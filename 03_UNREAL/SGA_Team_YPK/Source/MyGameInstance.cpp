// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
//TODO : YSR Particle
#include "MyEffectManager.h"
//TODO : YSR Sound
#include "MySoundManager.h"

#include "MyBossMonster.h"
#include "MyBossAIController.h"




void UMyGameInstance::InitializeManagers()
{
	//TODO : YSR Particle
	FActorSpawnParameters params;
	params.Name = TEXT("EffectManager");
	_effectManager = GetWorld()->SpawnActor<AMyEffectManager>(FVector::ZeroVector, FRotator::ZeroRotator, params);

	//TODO : YSR Sound
	params.Name = TEXT("SoundManager");
	_soundManager = GetWorld()->SpawnActor<AMySoundManager>(FVector::ZeroVector, FRotator::ZeroRotator, params);
}

