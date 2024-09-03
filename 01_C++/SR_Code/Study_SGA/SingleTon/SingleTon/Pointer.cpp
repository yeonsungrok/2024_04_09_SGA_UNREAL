#include <iostream>

using namespace std;

// call by value : 값에 의한 호출을 받음
void Add(int num)
{
	num += 1;
}

// call by adress : 주소에 의한 호출
void Add(int* num) // num은 aInt의 주소를 가리키는 포인터																★포인터 과정 : 3
{
	*num += 1;		// num이 가리키는 주소의 값을 1 증가 : aInt의 실제 값이 증가										★포인터 과정 : 4
}




int main() 
{
	int aInt = 0;		// aInt 값 0으로 선언, 초기화																	★포인터 과정 : 1
	Add(aInt);			// Add함수 호출 : aInt (0)의 값이 Add함수의 매개변수 num에 복사
							// void Add(int num)에서 num은 aInt의 복사본임 => 따라서 영향을 미치지 않아 0으로 출력.
	cout << aInt << endl;	// 출력 : 0

	Add(&aInt);			// Add 함수가 호출 : aInt의 주소가 Add 함수의 매개변수 num에 전달								★포인터 과정 : 2
	cout << aInt << endl;	// 출력 : 1																				★포인터 과정 : 5

	return 0;
}