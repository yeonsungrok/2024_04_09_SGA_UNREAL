#include <iostream>

#include <Thread>

using namespace std;

//void HelloThread()
//{
//    cout << "Hello Thread" << endl;
//}

//  atomic = 원자라는 뜻
atomic<int> sum = 0;

void Add()
{
    for (int i = 0; i < 100000; i++)
    {
        //sum++;
        sum.fetch_add(1);
    }
   
}
void Sub()
{
    for(int i = 0; i<100000; i++)
    {
         //sum--;
        sum.fetch_sub(1);
    }
}


int main()
{
    Add();
    Sub();
    // sum : 0
    std::thread t1(Add); // sum 10000
    std::thread t2(Sub);
    // 코드 : main

    t1.join();
    t2.join();

    cout << sum << endl;


    // 쓰레드는 사람 손이라고 생각하면 됨 (손 개수가 많으면 역할을 빨리 도와준다.)
    //std::thread t1(&HelloThread); // HelloThread라는 일감을 줌.

    ////t1.detach(); // 쓰레드 분리 (사용을 많이 한적이 없는 것 같음.)

    ////if(t1.joinable)
    //t1.join(); // 쓰레드가 끝날때까지 대기 후 Join      멀티쓰레드 경우 주쓰레드 외 다른 쓰레드로 실행을하고있는데 main은 주쓰레드.. 종료되면 나머지 HelloThread는 종료되지 않는다.. 그래서..



    return 0;
}
