#include <iostream>

using namespace std;
/*
SingleTon (�̱���)             --------- ������ �ƴϴ��� ���������� ��ü ����ϴ°͵��� ������ �����Ұ� ---------
1. �������� ������ �����ؾ��Ѵ�.
2. ���α׷��� �� �ϳ��� �����ؾ��Ѵ�.
3. �����Ҵ�Ǿ���Ѵ�. ----->>>>>   ������ ������ �����Ҵ��Ҽ��ֵ��� heap������ �����ϵ���..
*/

class SoundManager
{
private:
	SoundManager() {}
	~SoundManager() {}

public:
	// private ������ �� �ִ� ��� : public ����Լ�
	
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
	string _warriorSound = "������ ����!";
	string _archerSound = "��ó ����!";

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

	//SoundManager* sm2 = new SoundManager();   // �ܺο��� �������ϵ��� ���ƾ��Ѵ�... �׷���? �ܺο��� �������ϵ��� private

	/*delete sm;*/

	SoundManager::Create();		// ������ ����ó����..
	/*SoundManager::GetInstance()->PrintAllSound();*/
	Warrior* warrior = new Warrior();

	delete warrior;

	SoundManager::Delete();		// ������ ���帶������..

	return 0;
}