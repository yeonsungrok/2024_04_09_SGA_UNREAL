#pragma once

class Knight
{
public:
	Knight();
	Knight(int hp);
	~Knight();

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

	int GetAttackDamage();

	void OnDamaged(Knight* attacker, bool isCounterAttack = false); // 함수에 반격여부 추가

public:
	int _hp;
	int _maxHp;
	int _attack;
	bool _isCounterAttack;  // 반격 여부
};

