// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

//UENUM()
//enum class ItemType
//{
//
//};
//
//USTRUCT()
//struct ItemInfo
//{
//	int itemId;
//	ItemType type;
//};

UCLASS()
class UE5_CHARACTER_02_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	UFUNCTION() // ????????? ?????? ?? UFUNCTION ?????.
	void OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool BFromWeep, const FHitResult& SweepResult);

public:	
	void Init();
	void Disable();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ???��? item???
	void SetItemPos(FVector pos, FRotator rot = FRotator::ZeroRotator);

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* _meshComponent; // ??, ????? ??? ?????????????��?. ��????? ????? ACharacter?? ????????. ????? ????? ????? ?????????.
	
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* _trigger;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _itemId = -1;

};