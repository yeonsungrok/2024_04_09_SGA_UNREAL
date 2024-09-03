#include <iostream>

using namespace std;

// call by value 
void Add(int num)
{
	num += 1;
}

// call by adress 
void Add(int* num) 	
{
	*num += 1;									
}




int main() 
{
	int aInt = 0;														
	Add(aInt);			
							
	cout << aInt << endl;	

	Add(&aInt);			

	cout << aInt << endl;		

	return 0;
}