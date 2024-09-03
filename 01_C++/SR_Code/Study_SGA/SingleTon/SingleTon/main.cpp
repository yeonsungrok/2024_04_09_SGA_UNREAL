#include <iostream>

using namespace std;

// int 
// 크기 : 4

// ptr
// 크기 : 32비트운영체제 16진수 8개 => 4바이트
//        64비트운영체제 16진수 16개 => 64비트 => 8바이트

// 포인터 선언 방법
// (자료형)* (변수이름) = (초기화);
// (자료형)... 내가 주소값을 타고 들어가보면 (자료형)이 있을 것이다 라는 힌트
// void* : 타고들어가서 뭐가있든 상관하지 않겠다.

// 0.125
// 실수 ... float (4바이트)
// (부호 1)(지수 7) (유효숫자 23)

// 포인터 연산자
// (변수) * (변수) = 곱하기연산
// *(포인터 변수) .. 간접연산자 ... 포탈연산자 (포탈 타고 들어간다)
// (자료형)* (변수이름) .. 포인터 선언

// &(변수) &... 주소연산자
// (자료형) & (변수이름) = (초기화) &... 참조 선언
// (변수) & (변수)
// (변수) && (변수) : 논리연산자

										// 깊은복사 : 복사생성자, 복사대입연산자 둘다
											// 복사생성자
											// World(const World& other);
											// 복사 대입연산자
											// World& operator=(const World& other);



// 객체지향의 3속성
// 은닉성 : 접근지정자
// 상속성 : 
// 다형성 : 

class Vector2
{
public:
	// 클래스의 다형성 ... 연산자 오버로딩
	Vector2 operator+(const Vector2& other)
	{
		
	}

	int x;
	int y;
};

// 설계도
class Car
{
public:

	// private 멤버변수에 접근하려면 public 멤버함수
	void PrintEngine(int temp)
	{
		cout << _engine << endl;
	}

	int _handle = 0;

private:
	int _engine = 0;
	int _wheel = 1;
};


int main()
{
	// Stack
	// 12바이트

	Car car;
	car._handle = 1;


	return 0;
}
