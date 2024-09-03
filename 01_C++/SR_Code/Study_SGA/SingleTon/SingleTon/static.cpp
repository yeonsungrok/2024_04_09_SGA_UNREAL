#include <iostream>

using namespace std;

/*
디자인 패턴
    .... 프로그래밍 하면서 공통된 문제들을 해결하는 패턴을 정형화 해놓은 것

1. 싱글톤(SingleTon)
    - 객체를 단 하나만... 로직을 담당하는 얘들, 시스템적인 면을 담당하는 얘들
    - SoundManager (게임을 하다보면 설치할때 mp4도 여러가지 설치되어있다...)
    .... 맵에 10명이 있다고 가정했을때 때렸을때나는 사운드가 출력되야 할때마다 동적할당? (동적할당은 무거움... 게임로딩할때 사용함..)
    
    => SoundManager. 여기에 전사 10명의 목소리, 도적 10명의 목소리


static 변수와 static 함수에 대해서 조사
조사결과
    static 변수:
        함수 내부: 함수가 여러 번 호출되더라도 초기화가 한 번만 이루어지며, 프로그램 종료 시까지 값을 유지합니다.
        파일 범위: 해당 파일 내에서만 접근 가능한 전역 변수를 만듭니다.
        
    static 함수:
        해당 파일 내에서만 접근 가능한 함수를 만듭니다. 다른 파일에서는 호출할 수 없습니다.
        
        이러한 static 키워드의 사용은 모듈화와 정보 은닉에 도움을 주며, 특히 큰 프로젝트에서 코드의 가독성과 유지보수성을 높이는 데 기여

        
메모리영역
- Code

- Data
    --- 전역변수(Global), 정적변수(static)
    --- 프로그램이 시작할 때, 종료될때
- Stack
    --- [반환주소값][지역변수][매개변수]
    --- 함수 호출시, 지역 시작 / 함수종료시, 지역 끝
- Heap
    --- 내가 원하는 데이터 크기만큼
    --- 프로그래머가 원하는 대로





*/ 


//static int aInt = 0; //정적변수
//int bInt = 1;
//
//class Player
//{
//public:
//    int _hp = 0;
//    static int _mp;
//};
//int Player::_mp = 5;        // 밖에서 초기화 해야한다.
//
//
//// 정적함수
//static void HelloWorld()
//{
//    cout << "Hello World!" << endl;
//}

class Marine
{
public:
    void Print()
    {
        cout << _hp << endl;
        cout << atk << endl; // 멤버함수에서 정적멤버변수를 읽기 가능하다.
    }

    void Set(int hp, int atk)
    {
        _hp = hp;
        this->atk = atk;    // 멤버 함수에서 정적멤변수 쓰기가 가능하다.
    }

    // 정적멤버 함수
    // 멤버함수 호출 조건 : 객체가 무조건 있어야 한다.
    // 정적 멤버함수는 전역함수처럼 쓸수 있다. => 객체가 없어도 된다는 말.
    static void Print_S() 
    {
        // cout << this->hp << endl;    // 정적멤버함수는 멤버변수에 접근할 수 없다.
                                        // 정적멤버함수는 this를 누군지 특정할 수 없다.
        cout << atk << endl; // 정적멤버함수는 정적멤버변수에 접근할 수 있다. (모두 공유이기 때문에) 
    }


    int _hp = 0;
    static int atk;
};

int Marine::atk = 1;  // static을 정적에 밖에사용하지 않는다.





int main()
{
    //cout << aInt << endl;
    //HelloWorld();
    //
    ////Player::_hp = 5;   // 클래스는 설계도와 같다. (메모리상에 아무 영역에도 없기 때문이다..)
  
    //Player::_mp = 5;    // 정적 변수이기 때문에 data영역

    //Player* p = new Player();


    Marine* marines[100] = { nullptr };   // 건물은 만들었는데 내용이 없어서 최소 만들때 1byte 차지함으로 1byte
    for (int i = 0; i < 100; i++)
    {
        marines[i] = new Marine();
    }

    Marine::atk++;  // +1을 더해줌

    marines[0]->Set(100, 50);
    
    Marine::Print_S();

    cout << marines[5]->atk << endl;


    return 0;
}

