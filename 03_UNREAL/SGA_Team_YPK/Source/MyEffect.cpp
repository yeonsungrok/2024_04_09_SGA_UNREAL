// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEffect.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"


AMyEffect::AMyEffect()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	_particleCom = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	RootComponent = _particleCom;

	_particleSceneCom = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleScene"));
	_particleSceneCom->SetupAttachment(RootComponent);
		
}

void AMyEffect::BeginPlay()
{
	Super::BeginPlay();
	
	_particleCom->OnSystemFinished.AddDynamic(this, &AMyEffect::End);
	End(_particleCom);

	_particleSceneCom->OnSystemFinished.AddDynamic(this, &AMyEffect::End);
	End(_particleSceneCom);
}

void AMyEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyEffect::Play(FVector location, FRotator rotator)
{
	if (_particleCom->IsActive() || _particleSceneCom->IsActive())
		return;


	SetActorLocationAndRotation(location, rotator);
	_particleCom->ActivateSystem();
	_particleSceneCom->ActivateSystem();
}


bool AMyEffect::IsPlaying()
{
	if (_particleCom->IsActive())
		return true;

	if (_particleSceneCom->IsActive())
		return true;

	return false;
}


void AMyEffect::End(UParticleSystemComponent* particle)
{
	if (particle)
		particle->DeactivateSystem();
}

void AMyEffect::EndSystem(UParticleSystem* particle)
{
	if (particle && _particleSceneCom)
	{
		_particleSceneCom->SetTemplate(particle);
		_particleSceneCom->ActivateSystem();
	}

}


