#include "Knight.h"
#include <iostream>
using namespace std;

// [사양서] 기본값 Hp=100, Attack=10
Knight::Knight() : _hp(100), _maxHp(100), _attack(10)
{

}

Knight::Knight(int hp) : _hp(hp), _maxHp(hp), _attack(10)
{

}

Knight::~Knight()
{

}

void Knight::AddHp(int value)
{
	_hp += value;
	if (_hp < 0)						// maxHp를 추가하여 계산되도록 add에 설정
	{
		_hp = 0;
	}
	if (_hp > _maxHp)
	{
		_hp = _maxHp;
	}
}

bool Knight::IsDead()
{
	return (_hp <= 0);
}

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}