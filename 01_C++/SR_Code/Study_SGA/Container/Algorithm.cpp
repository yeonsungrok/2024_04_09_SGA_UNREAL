#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool Func(const int& value)
{
	if (value > 15)
		return true;

	return false;
}

int MultiplyThree(int num)
{
	return num * 3;
}

int main()
{
	vector<int> myV;

	myV.push_back(3);
	myV.push_back(5);
	myV.push_back(1);
	myV.push_back(7);
	myV.push_back(1);

	myV.push_back(21);
	myV.push_back(2);
	myV.push_back(4);
	myV.push_back(3);
	myV.push_back(5);


	// 1�� �ִ��� ã���ּ���. �׸��� index�� Ȥ�� iterator �ڸ��� ã���ּ���.
	int index = 0;
	for (int i = 0; i < myV.size(); i++)
	{
		if (myV[i] == 1)
		{
			index = i;
			break;
		}
	}

	vector<int>::iterator Iter = myV.begin();
	for (Iter; Iter != myV.end(); Iter++)
	{
		if (*Iter == 1)
		{
			break;
		}
	}

	cout << myV[index] << endl;
	cout << *Iter << endl;

	Iter = std::find(myV.begin(), myV.end(), 1);
	if (Iter != myV.end())
		cout << *Iter << endl;

	cout << "--------------------------------" << endl;


	// 15���� ū ���� �ִ��� ã���ּ���. �׸��� index�� Ȥ�� interator �ڸ��� ã���ּ���.
	int index2 = 0;
	for (int i = 0; i < myV.size(); i++)
	{
		if (myV[i] > 15)
		{
			index = i;
			break;
		}
	}

	vector<int>::iterator Iter2 = myV.begin();
	for (Iter2; Iter2 != myV.end(); Iter2++)
	{
		if (*Iter2 > 15)
		{
			break;
		}
	}

	cout << myV[index] << endl;
	cout << *Iter2 << endl;

	struct Finder_1
	{
		bool operator()(const int& value)
		{
			if (value > compareNum)
				return true;
			return false;
		}

		int compareNum = 0;
	};
	
	// �����Լ�, �����Լ�, �Լ���ü �� �� ����
	Iter = std::find_if(myV.begin(), myV.end(), &Func);
	cout << *Iter << endl;

	Finder_1 finder_1;
	finder_1.compareNum = 15;
	Iter = std::find_if(myV.begin(), myV.end(), finder_1);
	cout << *Iter << endl;

	cout << "--------------------------------" << endl;

	

	// ��� ���� 50���� ������ bool���� �˷��ּ���.
	struct Finder_2
	{
		bool operator()(const int& value)
		{
			if (value < compareNum)
				return true;
			return false;
		}

		int compareNum = 0;
	};

	Finder_2 finder_2;
	finder_2.compareNum = 50;
	cout << std::all_of(myV.begin(), myV.end(), finder_2) << endl;

	cout << "--------------------------------" << endl;


	// �ϳ��� 30���� ū ���� �ִ��� bool���� �˷��ּ���.
	Finder_1 finder_3;
	finder_3.compareNum = 30;
	cout << std::any_of(myV.begin(), myV.end(), finder_3) << endl;

	cout << "--------------------------------" << endl;


	// ���Ұ� 3�� ���ҵ��� ������ �˷��ּ���.
	cout << std::count(myV.begin(), myV.end(), 3) << endl;

	cout << "--------------------------------" << endl;


	// ���Ұ� 5���� ū ���ҵ��� ������ �˷��ּ���.
	Finder_1 finder_4;
	finder_4.compareNum = 5;
	cout << std::count_if(myV.begin(), myV.end(), finder_4) << endl;

	cout << "--------------------------------" << endl;


	// ��� ���ҿ� 3�� �����ּ���.

	struct Multiply
	{
		void operator()(int& value)
		{
			value *= _num;
		}

		int _num = 0;
	};

	Multiply multi_three;
	multi_three._num = 3;
	std::for_each(myV.begin(), myV.end(), multi_three);
	for (int i = 0; i < myV.size(); i++)
	{
		cout << myV[i] << endl;
	}

	cout << "--------------------------------" << endl;

	// �ߺ��� ���ҵ��� '����'���ּ���.


	// ���Ұ� 12�� ���Ҹ� �����ּ���.

	// ���Ұ� 10���� ���� ���ҵ��� �����ּ���.


	// std::find()


	return 0;
}