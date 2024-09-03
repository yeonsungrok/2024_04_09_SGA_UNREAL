#include <iostream>
using namespace std;

// Template
// 
// Class
// -> 객체(건물)을 찍어내는 설계도
// Template은 설계도를 찍어내는 애
//
// 함수 템플릿 : 함수를 찍어내는 애
// 템플릿 기본인자 (따로 지정 안하면 그걸로 만들어줌)
// 템플릿의 특수화
template<typename T>   // class T 라고 써도 됨 (어떤 자료형 T라는 뜻)

T Add(T a, T  b)
{
	T c = a + b;
	return c;
}


template<>
double Add(double a, double b)
{
	double c = a + b;
	cout << "Double" << endl;
	return c;
}

// 클래스 템플릿
template <typename T = int> // 클래스 템플릿 기본인자
class Player
{
public:
	T GetHp()
	{
		return _hp;
	}
	void SetHp(const T& hp)
	{
		_hp = hp;
	}

	T _hp;
	int _mp;
};

// 클래스 템플릿 특수화
template<>
class Player<double>
{
public:
	double _hp;
};


int main() 
{
	double c = Add<double>(1.2, 2.5);

	//float c = Add<float>(1.25f, 2.5f);

	Player<int> player;
	player.GetHp();

	Player<double> player2; 
	player2._hp;

	return 0;
}