// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"

#include "MyPlayer.generated.h"


/**
 * 
 */
UCLASS()
class UE5_CHARACTER_02_API AMyPlayer : public AMyCharacter
{
	GENERATED_BODY()
	
public:
	AMyPlayer();

	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	virtual void AttackHit() override;
protected:
	virtual void PlayAttackHitSound(FString SoundName, FVector location) override;
	

private:
	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);
	void JumpA(const FInputActionValue& value);
	void AttackA(const FInputActionValue& value);

	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _moveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _lookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _jumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _attackAction;

	//GŰ ����׼�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _dropAction;

	// ī�޶�(springArms ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* _springArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* _camera;




};
