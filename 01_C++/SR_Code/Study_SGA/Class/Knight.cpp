#include "pch.h"
#include "knight.h"

Knight::Knight()
// 빠른 초기화 영역
// 여기에 Creature() 숨어있음
{
	// 늦은 초기화 영역
	// cout << "Knight의 기본생성자" << endl;
	_stamina = 0;
}

Knight::Knight(int hp, int mp, int attack, int stamina)
	: Creature(hp, mp, attack)
{
	// cout << "Knight의 타입변환 생성자" << endl;
	_stamina = stamina;
}

Knight::~Knight()
{
	// cout << "Knight의 소멸자" << endl;
}



void Knight::PrintCreature()
{
	cout << "Knight의 HP : " << _hp << endl;
}