#include "pch.h"

// 1. Player를 상속받는 3가지 클래스를 만드세요.
// 2. main에 그 중 2개의 객체를 만드시고
// 3. 객체끼리 싸움을 합니다.
// 4. 이를 한명이 죽을 때 까지 반복

// 1. Player를 상속받는 Goblin ...(hp, mp, attack)
// 2. Main의 Creature 1명, Goblin 10명 배열을 만들어주세요.
// 3. 이 때 Goblin의 체력은 30 ~ 50 난수, 공격력은 2 ~ 5 까지 랜덤한 난수
// 4. Player가 죽거나 Goblin 10마리가 다 죽는 경우에 게임 끝. 그 외에 반복.
// ... 이 때 Goblin이 죽었다 하면 Attack은 동작하지 않게.
// 나는 고블린 한번에 다 때리고, 고블린은 10명이 한번에 나를 때림


// 1. Player를 상속받는 3가지 클래스를 만드세요.
// 2. main에 그 중 2개의 객체를 만드시고(동적할당, 자료형은 Creature*)
// 3. 객체끼리 싸움을 합니다.(Attack을 가상함수로 구현)
// 4. 이를 한명이 죽을 때 까지 반복

// -> 업캐스팅(자식->부모)된 객체가, 부모나 혹은 자식 클래스에서 virtual 키워드로 함수를 선언할 때
// vftable이 만들어지고, 이를 추적하여 해당 타입에 맞는 함수를 호출하게 된다.




// 사양서 1
// 1. 1~3의 수를 입력받아서 Knight, Archer, Mage 세 직업중 하나를 선택해 생성(동적할당)하게 해주세요.
// 2. 컴퓨터도 난수를 받아서 1.과 같이 세팅해주세요.
// 3. 플레이어의 이름을 입력받고 Set 해주세요. 컴퓨터는 컴퓨터로.
// 4. 공격할 때 서로의 이름이 표시되게 해주세요. 예) Hanil이 컴퓨터를 공격했습니다.
// 5. Knight는 체력이 50프로 미만이 되면 공격력이 2배 강해집니다.
// 6. Mage는 마나를 5만큼 소비하여 공격을 합니다. 공격할 때 마나가 부족하다면 50만큼 회복하고 공격을 쉽니다.
// 7. Archer 30프로 확률로 크리티컬 데미지(3배 공격)을 합니다. 
// 8. 이 때 누가 이기는지 체크하고 이길 때 까지 반복


// 사양서 2
// 0. 컴퓨터와 전투할지 사냥으로 경험치를 얻을지 1, 2 입력으로 선택 (컴퓨터와 전투 패배시 혹은 고블린과 전투 후 0번으로 돌아옴)
// 1. Creature를 상속받는 Player를 만듭니다.
// 2. 사양서 1의 Knight와 Arhcher, Mage는 Player를 상속받습니다. 이 때 Player는 추상클래스입니다. 
// 3. Player의 속성에서 경험치가 추가됩니다.
// 4. Player가 고블린 10마리와 싸우는 전투에서 경험치를 얻고 경험치에 따라서 스탯이 올라갑니다. 
// 5. 전투가 끝나고 사양서 1의 게임을 다시해서 이기면 프로그램 종료



void PrintPlayers(Creature* p1, Creature* p2)
{
	p1->PrintCreature();
	p2->PrintCreature();
}

int main()
{
	//	Creature* player = new Creature(100, 100, 5);
	//	Goblin* goblin_G[10]; 
	//	
	//
	//	// 10개 한번에 뭉텅이로 넣고 포인터 받아올때 쓸수는 있는데 잘 안씀
	//	Goblin* goblins = new Goblin[10];
	//	delete[] goblins;
	//
	//
	//	srand(time(NULL));
	//
	//	for (int i = 0; i < 10; i++)
	//	{
	//		int time = rand();
	//		goblin_G[i] = new Goblin();
	//		goblin_G[i]->SetStat(time);
	//	}
	//
	//	while (true)
	//	{
	//		// 내가 공격
	//		cout << endl;
	//		cout << "Creature의 공격!!!" << endl;
	//		for (int i = 0; i < 10; i++)
	//		{
	//			if (goblin_G[i]->IsDead())
	//			{
	//			}
	//			else
	//			{
	//				player->Attack(goblin_G[i]);
	//				goblin_G[i]->PrintPlayerGroup(*goblin_G[i], i);
	//			}
	//		}
	//
	//		if ((*goblin_G)->AllDead(*goblin_G, 10))
	//		{
	//			cout << endl;
	//			cout << "이겼습니다!" << endl;
	//			break;
	//		}
	//
	//		// 고블린이 공격
	//		cout << endl;
	//		cout << "Goblin의 공격!!!" << endl;
	//		for (int i = 0; i < 10; i++)
	//		{
	//			if (goblin_G[i]->IsDead())
	//			{
	//			}
	//			else
	//			{
	//				goblin_G[i]->Attack(player);
	//			}
	//		}
	//
	//		player->PrintCreature();
	//
	//		if (player->IsDead())
	//		{
	//			cout << endl;
	//			cout << "졌습니다!" << endl;
	//			break;
	//		}
	//	}
	//
	//
	//	for (int i = 0; i < 10; i++) // -> 해제도 for문 돌면서 해야함
	//	{
	//		delete goblin_G[i];
	//	}
	//
	//	delete player;
	//
	//
	//	return 0;
	//}
	//
	//	// 1. Player를 상속받는 3가지 클래스를 만드세요.
	//	// 2. main에 그 중 2개의 객체를 만드시고(동적할당, 자료형은 Creature*)
	//	// 3. 객체끼리 싸움을 합니다.(Attack을 가상함수로 구현)
	//	// 4. 이를 한명이 죽을 때 까지 반복
	//
	//	// Creature* player = new Creature(50, 10, 5);
	//	// Creature* knight = new Knight(100, 5, 15, 100);
	//	// 
	//	// 
	//	// while (true)
	//	// {
	//	// 	player->Attack(knight);
	//	// 	PrintPlayers(player, knight);
	//	// 	cout << endl;
	//	// 
	//	// 	knight->Attack(player);
	//	// 	PrintPlayers(player, knight);
	//	// 	cout << endl;
	//	// 
	//	// 	if (player->IsDead())
	//	// 	{
	//	// 		cout << "졌습니다!!!" <<  endl;
	//	// 		break;
	//	// 	}
	//	// 
	//	// 	else if (knight->IsDead())
	//	// 	{
	//	// 		cout << "이겼습니다!!!" << endl;
	//	// 		break;
	//	// 	}
	//	// }
	//	// 
	//	// delete knight; // virtual 안쓰면 Player만 없어짐
	//	// delete player;
	//	// 
	//	// 
	//	// 
	//	// return 0;
	//
	//
	//	// Creature p(50, 10, 5);
	//	// Knight k(100, 5, 15, 100);
	//	// 
	//	// while (true)
	//	// {
	//	// 	p.Attack(&k);
	//	// 	k.Attack(&p);
	//	// 	
	//	// 
	//	// 	if (p.IsDead() || k.IsDead())
	//	// 	{
	//	// 		break;
	//	// 	}
	//	// }
	//	// 
	//	// p.PrintCreature();
	//
	//	
	//	
	//	
	//	// Creature p(100, 100, 5);
	//	// Goblin g_arr[10];
	//	// 
	//	// srand(time(NULL));
	//	// for (int i = 0; i < 10; i++)
	//	// {
	//	// 	int time = rand();
	//	// 	g_arr[i].SetStat(time);
	//	// }
	//	// 
	//	// while (true)
	//	// {
	//	// 	// 내가 공격
	//	// 	cout << endl;
	//	// 	cout << "Player의 공격!!!" << endl;
	//	// 	for (int i = 0; i < 10; i++)
	//	// 	{
	//	// 		if (g_arr[i].IsDead())
	//	// 		{
	//	// 		}
	//	// 		else
	//	// 		{
	//	// 			p.Attack(&g_arr[i]);
	//	// 			g_arr[i].PrintGoblin(g_arr[i], i);
	//	// 		}
	//	// 	}
	//	// 
	//	// 	if (g_arr->AllDead(g_arr, 10))
	//	// 	{
	//	// 		cout << endl;
	//	// 		cout << "이겼습니다!" << endl;
	//	// 		break;
	//	// 	}
	//	// 
	//	// 	// 고블린이 공격
	//	// 	cout << endl;
	//	// 	cout << "Goblin의 공격!!!" << endl;
	//	// 	for (int i = 0; i < 10; i++)
	//	// 	{
	//	// 		if (g_arr[i].IsDead())
	//	// 		{
	//	// 		}
	//	// 		else
	//	// 		{
	//	// 			g_arr[i].Attack(&p);
	//	// 		}
	//	// 	}
	//	// 
	//	// 	p.PrintCreature();
	//	// 
	//	// 	if (p.IsDead())
	//	// 	{
	//	// 		cout << endl;
	//	// 		cout << "졌습니다!" << endl;
	//	// 		break;
	//	// 	}
	//	// 
	//	// }
	//	// 


	string name;
	cin >> name;

	Creature* knight = new Knight(500, 2, 15, 0);
	knight->SetName(name);

	knight->PrintCreature();

	delete knight;

	return 0;

}