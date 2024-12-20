// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Service_FindTarget.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "DrawDebugHelpers.h"
#include "Engine/OverlapResult.h"
#include "MyPlayer.h"

UBT_Service_FindTarget::UBT_Service_FindTarget()
{
	NodeName = TEXT("FindTarget");
	Interval = 0.5f;
}

void UBT_Service_FindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto currentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (currentPawn == nullptr)
		return;
	
	auto world = GetWorld();
	FVector center = currentPawn->GetActorLocation();
	float searchRadius = 500.0f;

	if (world == nullptr)
		return;

	TArray<FOverlapResult> overLapResult;
	FCollisionQueryParams qparams(NAME_None, false, currentPawn);

	bool bResult = world->OverlapMultiByChannel //감지를 1명이 아니라 가장 가까이 있는것을 탐색하기위해 Single대신 Multi로..
		(
			overLapResult,
			center,
			FQuat::Identity,
			ECollisionChannel::ECC_GameTraceChannel2,
			FCollisionShape::MakeSphere(searchRadius),
			qparams
		);

	if (bResult)
	{
		for (auto& result : overLapResult)
		{
			auto myCharacter = Cast<AMyPlayer>(result.GetActor());
			
			if (myCharacter != nullptr)
			{
				auto myCharacterController = myCharacter->GetController();

				if (myCharacterController != nullptr && myCharacterController->IsPlayerController())
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), myCharacter); // 타겟 myCharacter
					DrawDebugSphere(world, center, searchRadius, 32, FColor::Red, false, 0.3f);
				}

				return;
			}
		}

		//DEBUG : DrawCapsule
		//DrawDebugSphere(world, center, searchRadius, 32, FColor::Green, false, 0.3f);

	}
	else
	{
		//DEBUG : DrawCapsule
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr); // 타겟없으니 nullptr
		//DrawDebugSphere(world, center, searchRadius, 32, FColor::Green, false, 0.3f);
	}


}
