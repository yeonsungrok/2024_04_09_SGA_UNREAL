#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) : _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp), _pet(nullptr)     // pet nullptr�� �߰�
{
}

Archer::~Archer()
{
	// �ܺο��� ��������
	// ��ſ��� �� �� :(
	/*if (_pet != nullptr)
		delete _pet;*/
}

