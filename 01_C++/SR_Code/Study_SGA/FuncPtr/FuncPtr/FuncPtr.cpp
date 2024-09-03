#include <iostream>
using namespace std;

/*
함수도 어딘가에는 저장되어있지 않을까?
예) vftable...
*/

// 함수 이름이 포인터와 동일하게 동작한다.
// 배열...

// 콜백함수
// - (다른함수도) 인자로 전달되어 호출되는 함수  =  중요!!!! ==== 함수가 인자로 전달된다면 콜백함수


void HelloWorld()
{
    cout << "Hello World" << endl;
}

void PrintHello()
{
    cout << "안녕하세요" << endl;
}


void PrintNum(int number)
{
    cout << number << endl;
}



// 함수 포인터 
// 함수 선언방법 : (반환자료형) 함수이름 (매개변수) => 함수 시그니처

// (반환 자료형) (* 포인터이름) (매개변수)
void(*func)(void);
void(*funcInt)(int);

class Pet;
// 맴버 함수 포인트
void(Pet::* func1)(void); // 꼭 필요함

class Pet   // 맴버함수도 가능한지 확인하기위한 클래스도 만듬
{
public:
    // 강아지 static.... 못적음...


    void Sound() 
    {
        cout << "냐용" << endl;
    }

private:

};


class Player
{
public:
    void Excute()
    {
        // 예) 공격

        if (_func != nullptr) // 예) 사운드
            _func();
    }

    void PetExcute()
    {
        if (_petFunc != nullptr && _pet != nullptr)
            (_pet->* _petFunc)();  // 맴버함수 호출할때는 객체가 반드시 필요... 그냥 _petFunc();로만 안됨.. 

    }


    void SetFunc(void(*func)(void))
    {
        _func = func;
    }

    void SetPetFunc(Pet* pet, void(Pet::* func)(void))
    {
        _petFunc = func;
        _pet = pet;
    }


private:
    void(*_func)(void) = nullptr;
    void(Pet::* _petFunc)(void) = nullptr;  // 누구의 맴버함수인지... 꼭 알아야한다.
    Pet* _pet = nullptr;
};


int main()
{
    func = &HelloWorld;
    funcInt = &PrintNum;
    
    func();

    Player* p = new Player();
    
    // 플레이어를 몰라도 함수를 달라고하여 호출할 수 있다. 1콜백함수의 장점
    p->SetFunc(&PrintHello);   // 중요!!!! ==== 함수가 인자로 전달된다면 콜백함수
    p->Excute();
    p->SetFunc(&HelloWorld);
    p->Excute();

    Pet* pet = new Pet();
    p->SetPetFunc(pet, &Pet::Sound);
    p->PetExcute();

    p->Excute(); // 함수를 저장해놓고 호출이원할때 호출하는 것이 콜백함수

    return 0;
}

