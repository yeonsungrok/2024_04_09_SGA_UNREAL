#include "Archer.h"
#include "Pet.h"

Archer::Archer()
{
	// �̷� ���� ���� ä�� ����~
	_pet = new Pet(); // �����Ҵ�
}

Archer::Archer(int hp) : Player(hp)
{
	// �̷� ���� ���� ä�� ����~
	_pet = new Pet();
}

Archer::~Archer()
{
	// ��ſ��� �� �� :(
	if (_pet != nullptr)    // ȣ���� �ȵ� - �Ҹ��ڰ�...
		delete _pet;
}

