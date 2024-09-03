#include "pch.h"
#include "Goblin.h"

Goblin::Goblin()
{
}

Goblin::Goblin(int hp, int mp, int attack)
	:Creature(hp, mp, attack)
{
}

Goblin::~Goblin()
{
}

void Goblin::SetStat(int time)
{
	_hp = time % 21 + 30;
	_mp = 100;
	_attack = time % 4 + 2;

}

bool Goblin::AllDead(Goblin arr[], int size)
{
	bool Dead = true;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].IsDead())
		{
		}
		else
		{
			Dead = false;
		}

	}

	return Dead;
}


//
//void Goblin::PrintPlayerGroup(Creature p, int index)
//{
//		cout << "Goblin " << index + 1 << " HP : " << p.HP() << endl;
//}

void Goblin::Attack(Creature* p)
{
	p->TakeDamage(_attack);
}