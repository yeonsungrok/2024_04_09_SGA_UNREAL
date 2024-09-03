#pragma once

#include "Creature.h"


class Creature; // 전방선언

class Knight : public Creature
{
public:
	Knight();
	Knight(int hp, int mp, int attack, int stamina);
	virtual ~Knight();

	// 함수 오버라이딩 : 부모의 함수를 재정의
	virtual void Attack(Creature* p) override;
	virtual void PrintCreature() override;


private:
	int _stamina;
};