// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEffectManager.h"

#include "Components/SceneComponent.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "MyEffect.h"



AMyEffectManager::AMyEffectManager()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	_rootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComponent = _rootComponent;
	CreateParticleClass(TEXT("ky_hit_slash"), TEXT("/Script/Engine.Blueprint'/Game/Blueprint/VFX/MyEffect_BP.MyEffect_BP_C'"));
	CreateParticleClass(TEXT("ky_stab"), TEXT("/Script/Engine.Blueprint'/Game/Blueprint/VFX/MyEffect_AttackArcher_BP.MyEffect_AttackArcher_BP_C'"));
	CreateParticleClass(TEXT("ky_flash1"), TEXT("/Script/Engine.Blueprint'/Game/Blueprint/VFX/MyEffect_AttackMonster_BP.MyEffect_AttackMonster_BP_C'"));

	
}

void AMyEffectManager::CreateParticleClass(FString name, FString path)
{
	if (_classTable.Contains(name) == true)
	{
		UE_LOG(LogTemp, Error, TEXT("%s already exists in classTable"), *name);
		return;
	}


    ConstructorHelpers::FClassFinder<AMyEffect> effect(*path);
	if (effect.Succeeded())
	{
		_classTable.Add(name);
		_classTable[name] = effect.Class;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find : %s"), *path);
		return;
	}

}

void AMyEffectManager::BeginPlay()
{
	Super::BeginPlay();
	
	CreateEffect();
}

void AMyEffectManager::CreateEffect()
{
	for (auto classPair : _classTable)
	{
		FString name = classPair.Key;

		_effectTable.Add(name);
		for (int32 i = 0; i < _poolCount; i++)
		{
			FString tempName = name + FString::FromInt(i);
			FActorSpawnParameters params;
			params.Name = FName(*tempName);
			auto effect = GetWorld()->SpawnActor<AMyEffect>(classPair.Value, FVector::ZeroVector, FRotator::ZeroRotator, params);

			effect->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
			_effectTable[name].Add(effect);
		}
	}
}

void AMyEffectManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyEffectManager::Play(FString name, FVector location, FRotator rotator)
{
	
	if (_effectTable.Contains(name) == false)
		return;

	auto findEffect = _effectTable[name].FindByPredicate(
		[](AMyEffect* effect)-> bool
		{
			if (effect->IsPlaying())
				return false;
			return true;
		});

	if (findEffect)
		(*findEffect)->Play(location, rotator);
}