#pragma once

#include "Creature.h"

class Goblin : public Creature
{
public:
	Goblin();
	Goblin(int hp, int mp, int attack);
	virtual ~Goblin(); // 자식 구분되게 override 써도 되도 안써도 됨

	void SetStat(int time);

	void SetHP(int hp) { _hp = hp; }

	bool AllDead(Goblin arr[], int size);

	// void PrintPlayerGroup(Creature p, int index);

	virtual void Attack(Creature* p) override;


};