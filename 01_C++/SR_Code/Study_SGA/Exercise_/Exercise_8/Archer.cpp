#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) : _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp), _pet(nullptr)     // pet nullptr로 추가
{
}

Archer::~Archer()
{
	// 외부에서 삭제했음
	// 즐거웠다 내 펫 :(
	/*if (_pet != nullptr)
		delete _pet;*/
}

