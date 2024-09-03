#include <iostream>
using namespace std;

struct Item
{
	void PrintItem()
	{
		cout << "Price : " << price << endl;
		cout << "Tire : " << tier << endl;
		cout << "Atk : " << atk << endl;
	}
	int price;		
	int tier;		
	int atk;		
};

// 함수로 찾는 방법
Item* FindItem_Price(Item* arr, int size, int price)
{
	// 매개변수 price에 맞는 아이템을 찾아서 return, 만약 없다면 nullptr 반환
	Item* result = nullptr;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].price == price)
			result = &arr[i];
	}
	return result; 
}



// 함수 포인터를 이용해서 찾는 방법
Item* FindItem_FuncPtr(Item* arr, int size, bool(*func)(const Item&)) 
{
	Item* result = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]))
			result = &arr[i];
	}
	return result;
}
bool FineItemPtr_Price(const Item& item)
{
	if (item.price == 1500)
		return true;
}
bool FineItemPtr_Tier(const Item& item) 
{
	if (item.tier == 5)
		return true;
	return false;
}

// 함수 객체로 찾는 방법
struct Finder
{
	bool operator()(const Item& item)
	{
		if (itemPrice == item.price)
			return true;
		return false;
	}

	int itemPrice;
	int itemTire;
	int itemAtk;
};
Item* FindItem_Functor(Item* arr, int size, Finder finder)
{
	Item* result = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (finder(arr[i]))
			result = &arr[i];
	}
	return result;
}

int main() 
{ 
	Item items[10];
	for (int i = 0; i < 10; i++)
	{
		items[i].price = 500 * (i + 1) * 3;
		items[i].tier = (10 - i);
		items[i].atk = 10 * (i + 1);
	}
	
	Item* finditem = FindItem_Price(items, 10, 4500);
	if (finditem != nullptr)
		finditem->PrintItem();

	finditem = nullptr;
	finditem = FindItem_FuncPtr(items, 10, &FineItemPtr_Price);
	if (finditem != nullptr)
		finditem->PrintItem();

	Finder finder;
	// 가격 3000인 애 찾기
	finder.itemPrice = 3000;
	finditem = FindItem_Functor(items, 10, finder);
	if (finditem != nullptr)
		finditem->PrintItem();
	



	return 0; 
}