#include "pch.h"
#include "CannonScene.h"
#include "Objects/Cannon.h"
#include "Objects/Bullet.h"

// 사양서 (수요일까지.. 7/3..)
// 턴제 포트리스
// 각 cannon은 턴마다 서로 컨트롤을 받아서 공격
// cannon의 HP는 5
// 맞으면 hp -1, hp가 0이면 cannon이 사라짐(false로 만들어야겠지?)

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();

	_cannon1->isControlled = true;
	_cannon2->isControlled = false;


	

	//어택2
	for (auto bullet : _cannon1->GetBullets())
	{
		bullet->SetTarget(_cannon2);
		
	}

	for (auto bullet : _cannon2->GetBullets())
	{
		bullet->SetTarget(_cannon1);
		
		
	/*	if (_cannon2->GetCollider())
		{
			_cannon1->Damage(1);
		}*/
	}

}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	if (_cannon1->isActive())
	{
		_cannon1->Update();
		if (_cannon1->isControlled)
		{
			_cannon1->TurnPattern(_cannon2);
		}
	}


	if (_cannon2->isActive())
	{
		_cannon2->Update();

		if (_cannon2->isControlled)
		{
			_cannon2->TurnPattern(_cannon1);
		}
	}


	
	
	/*_cannon1->CheckCollision(_cannon2);
	
	_cannon2->CheckCollision(_cannon1);*/


	//어택 1
	//for (auto bullet : _cannon1->GetBullets())
	//{
	//	bullet->Attack_Cannon(_cannon2);
	//}
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
	
	

}
