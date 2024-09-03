#include "Archer.h"
#include "Pet.h"

Archer::Archer()
{
	// 이런 저런 정보 채울 예정~
	_pet = new Pet(); // 동적할당
}

Archer::Archer(int hp) : Player(hp)
{
	// 이런 저런 정보 채울 예정~
	_pet = new Pet();
}

Archer::~Archer()
{
	// 즐거웠다 내 펫 :(
	if (_pet != nullptr)    // 호출이 안됨 - 소멸자가...
		delete _pet;
}

