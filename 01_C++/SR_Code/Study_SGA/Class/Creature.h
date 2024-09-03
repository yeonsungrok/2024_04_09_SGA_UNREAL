#pragma once

class Creature
{
public:

	Creature();
	Creature(int hp, int mp, int attack);
	virtual ~Creature();

	virtual void PrintCreature();

	virtual void Attack(Creature* p) abstract;
	void TakeDamage(int amount);

	const int& HP() { return _hp; }
	bool IsDead() { return _hp <= 0; }

	void SetName(const string& name);



protected:
	int _hp;
	int _mp;
	int _attack;
	string _name;

};

