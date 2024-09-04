// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyStatComponent.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */

 //TODO : YSR Particle
class AMyEffectManager;
class AMySoundManager;
#define EffectManager Cast<UMyGameInstance>(GetGameInstance())->GetEffectManager()
#define SoundManager Cast<UMyGameInstance>(GetGameInstance())->GetSoundManager()

UCLASS()
class SGA_TEAM_YPK_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance();

	//TODO : YSR Particle
	AMyEffectManager* GetEffectManager() { return _effectManager; }
	AMySoundManager* GetSoundManager() { return _soundManager; }


private:
	
	//TODO : YSR Particle
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	AMyEffectManager* _effectManager;

	//TODO : YSR Sound
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	AMySoundManager* _soundManager;


};
