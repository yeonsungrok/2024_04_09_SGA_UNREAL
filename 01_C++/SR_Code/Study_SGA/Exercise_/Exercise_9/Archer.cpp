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
	// 즐거웠다 내 펫 :(
	_pet = nullptr;
}

void Archer::AddHp(int value)
{
	Player::AddHp(value);

	// 죽었으면 펫도 날린다
	if (IsDead())
	{
		// 죽었으면 지우는게 아니라 nullptr로 날린것
		_pet = nullptr;
	}
}
