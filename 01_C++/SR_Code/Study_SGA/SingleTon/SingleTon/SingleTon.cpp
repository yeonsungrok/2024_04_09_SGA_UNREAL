#include <iostream>

using namespace std;
/*
SingleTon (싱글톤)             --------- 게임이 아니더라도 전반적으로 전체 사용하는것들이 있으니 참조할것 ---------
1. 전역으로 접근이 가능해야한다.
2. 프로그램에 단 하나만 존재해야한다.
3. 동적할당되어야한다. ----->>>>>   데이터 때문에 동적할당할수있도록 heap영역에 가능하도록..
*/

class SoundManager
{
private:
	SoundManager() {}
	~SoundManager() {}

public:
	// private 접근할 수 있는 방법 : public 멤버함수
	
	static void Create()
	{
		if (instance == nullptr)
		{
			instance = new SoundManager();
		}
	}
	static void Delete()
	{
		if (instance != nullptr)
		{
			delete instance;
		}
	}

	static SoundManager* GetInstance()
	{
		if (instance != nullptr)
			return instance;
		return nullptr;
	}

	void PrintAllSound()
	{
		cout << _warriorSound << endl;
		cout << _archerSound << endl;
	}

	void PrintWarriorSound()
	{
		cout << _warriorSound << endl;
	}

private:
	static SoundManager* instance;
	string _warriorSound = "워리어 등장!";
	string _archerSound = "아처 등장!";

};

SoundManager* SoundManager::instance = nullptr;

// SoundManager* sm = new SoundManager();

class Warrior
{
public:
	Warrior() { SoundManager::GetInstance()->PrintWarriorSound(); }
};


int main() 
{
	/*sm->PrintAllSound();*/

	//SoundManager* sm2 = new SoundManager();   // 외부에서 생성못하도록 막아야한다... 그래서? 외부에서 생성못하도록 private

	/*delete sm;*/

	SoundManager::Create();		// 생성도 가장처음에..
	/*SoundManager::GetInstance()->PrintAllSound();*/
	Warrior* warrior = new Warrior();

	delete warrior;

	SoundManager::Delete();		// 삭제도 가장마지막에..

	return 0;
}