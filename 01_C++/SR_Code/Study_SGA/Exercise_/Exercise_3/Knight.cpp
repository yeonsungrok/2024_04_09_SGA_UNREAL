#include "Knight.h"
#include <iostream>
using namespace std;

// [사양서] 기본값 Hp=100, Attack=10
Knight::Knight() : _hp(100), _attack(10)
{

}

Knight::Knight(int hp) : _hp(hp), _attack(10)
{

}

Knight::~Knight()
{

}

void Knight::AddHp(int value)
{
	_hp += value;
}

bool Knight::IsDead()
{
	return (_hp <= 0);           // return 값이 0과 같다만 되있기보다는 그 밑으로 음수가 됬을때도 반환호출되도록 설정 <=
}

void Knight::PrintInfo()
{
	cout << _hp << endl;
	cout << _attack << endl;
}