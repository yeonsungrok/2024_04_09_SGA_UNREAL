#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;
/*
// 1. auto
// --> 반드시 초기화 해줘야함
// 2. 중괄호 초기화

// 3. 범위기반 for문
// 4. finel, freind
// 5. using
// --> typedef 와 다른장점은 템플릿과 호환이 된다..
// 6. enum class


//6/20
// 7. 람다
// 8. 이동 shift 개념
// 9. 스마트 포인터
*/
class Player
{
public:
	virtual void PrintP() {}

	int _hp = 0;
};

class Knight : public Player
{
public:
	friend class KnightHelper;				// 4번내용 : 사용할수 있도록 ...

	virtual void PrintP() final override{}  // 4번내용
	int _stamina = 0;
};

class HolyKnight : public Knight
{
public:
	//virtual void PrintP() override {} // 재정의 안됨
};

class KnightHelper
{
public:
	void PrintK(Knight* k) { k->_stamina; }
};


typedef void(*FuncPtr)(void);
typedef unsigned int UINT; //왼쪽내용을  오른쪽으로 교체하겠다...

using UINT2 = unsigned int;
using FuncPtr2 = void(*)(void);

void Hello()
{
	cout << "Hello" << endl;
}

enum class PlayerType
{
	NONE,
	KNIGHT,
	ARCHER,
	MAGE

};

enum class WarriorType
{
	NONE,
	HOLLYKNIGHT,
	WARRIOR,
	KNIGHT

};

int main()
{
	auto aInt = { 5 };

	auto aDoble = { 1.4 };

	// 파이썬은 타입 안써도된다... 그럼 auto 는 언제쓰는지?
	vector<int> tempV = {1,2,3,4,5,626,342,324523452,23};

	auto vIter = tempV.begin();

	for (vIter; vIter != tempV.end(); vIter++)
	{

	}

	unordered_map<int, int> temp_uM;
	temp_uM[0] = 1;
	temp_uM[1] = -1;
	temp_uM[2] = 311;
	temp_uM[5] = 100;
	temp_uM[8] = 123;

	auto umIter = temp_uM.begin();
	for (umIter; umIter != temp_uM.end(); umIter++)
	{

	}

	//for (int& data : tempV) // 3번내용
	//{
	//	data = 0;
	//	cout << data << endl;
	//}

	for (auto& p : temp_uM) // 3번내용 : 범위경 for문
	{
		p.second *= 5; // 원본에서 갖고온것이 아니라 복사해서 갖고온것이다.. (p) 그래서 참조 &를 붙여야한다.
		cout << "key : " << p.first << "value : " << p.second << endl;

	}


	// -------------- 5번 --------------------------- 
	
	UINT aUInt = 5;

	FuncPtr funcPtr;
	funcPtr = &Hello;
	funcPtr();

	//PlayerType type = ARCHER;


	// -------------- 6번 --------------------------- 
	int type = static_cast<int>(WarriorType::KNIGHT);  // enum class... 6번




	return 0;
}

