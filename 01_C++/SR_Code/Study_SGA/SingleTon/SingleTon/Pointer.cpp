#include <iostream>

using namespace std;

// call by value : ���� ���� ȣ���� ����
void Add(int num)
{
	num += 1;
}

// call by adress : �ּҿ� ���� ȣ��
void Add(int* num) // num�� aInt�� �ּҸ� ����Ű�� ������																�������� ���� : 3
{
	*num += 1;		// num�� ����Ű�� �ּ��� ���� 1 ���� : aInt�� ���� ���� ����										�������� ���� : 4
}




int main() 
{
	int aInt = 0;		// aInt �� 0���� ����, �ʱ�ȭ																	�������� ���� : 1
	Add(aInt);			// Add�Լ� ȣ�� : aInt (0)�� ���� Add�Լ��� �Ű����� num�� ����
							// void Add(int num)���� num�� aInt�� ���纻�� => ���� ������ ��ġ�� �ʾ� 0���� ���.
	cout << aInt << endl;	// ��� : 0

	Add(&aInt);			// Add �Լ��� ȣ�� : aInt�� �ּҰ� Add �Լ��� �Ű����� num�� ����								�������� ���� : 2
	cout << aInt << endl;	// ��� : 1																				�������� ���� : 5

	return 0;
}