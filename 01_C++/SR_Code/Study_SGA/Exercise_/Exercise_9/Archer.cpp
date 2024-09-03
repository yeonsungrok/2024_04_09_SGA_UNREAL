#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) : _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp), _pet(nullptr)
{
}

Archer::~Archer()
{
	_pet = nullptr;
}

void Archer::AddHp(int value)
{
	Player::AddHp(value);

	// �׾����� �굵 ������
	if (IsDead())
	{
		// �׾����� ����°� �ƴ϶� nullptr�� ������
		_pet = nullptr;
	}
}
