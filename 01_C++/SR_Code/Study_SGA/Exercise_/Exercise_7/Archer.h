#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer();
	Archer(int hp);
	virtual ~Archer();

	//Wvoid Pet(Archer* player); // 

public:
	class Pet* _pet;
};

