#include "Knight.h"
#include <iostream>
using namespace std;

// Hp=100, Attack=10
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
	return (_hp <= 0);          
}

void Knight::PrintInfo()
{
	cout << _hp << endl;
	cout << _attack << endl;
}