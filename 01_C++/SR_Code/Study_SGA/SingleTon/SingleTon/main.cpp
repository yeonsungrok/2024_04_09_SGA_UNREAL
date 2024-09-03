#include <iostream>

using namespace std;


class Vector2
{
public:
	
	Vector2 operator+(const Vector2& other)
	{
		
	}

	int x;
	int y;
};

class Car
{
public:

	
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
	
	Car car;
	car._handle = 1;


	return 0;
}
