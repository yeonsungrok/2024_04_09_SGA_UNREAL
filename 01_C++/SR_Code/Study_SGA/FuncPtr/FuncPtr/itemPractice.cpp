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
	if (item.price == 9000 || item.price == 3000)
		return true;
}
bool FineItemPtr_Tier(const Item& item) 
{
	if (item.tier == 8 || item.tier == 5)
		return true;
	return false;
}
bool FineItemPtr_Atk(const Item& item)
{
	if (item.atk == 20)
		return true;
	return false;
}



struct Finder
{
	bool operator()(const Item& item)
	{
		if (itemPrice == item.price && itemTire == item.tier)
			return true;
		return false;
	}

	int itemPrice;
	int itemTire;
	int itemAtk;
};
template <typename I, typename T>
Item* FindItem_Functor(I arr[], int size, T finder)
{
	I* result = nullptr;
	for (int i = 0; i < size; i++)
	{

		if (finder(arr[i]))
			result = &arr[i];
	}
	return result;
}

//Item* FindItem_Functor(Item* arr, int size, Finder finder)
//{
//	Item* result = nullptr;
//	for (int i = 0; i < size; i++)
//	{
//		if (finder(arr[i]))
//			result = &arr[i];
//	}
//	return result;
//}
//template <typename T>
//I* FindBy_Functor(I arr[], int size, T finder)


struct Finder_All
{
	bool operator()(const Item& item)
	{
		if (price == item.price && tier == item.tier && atk == item.atk)
			return true;
		return false;
	}

	int price;
	int tier;
	int atk;
};
struct Finder_Two
{
	bool operator()(const Item& item)
	{
		if (price == item.price && tier == item.tier && atk == item.atk)
			return true;
		return false;
	}

	int price;
	int tier;
	int atk;
};




int main()
{
	Item items[10];
	for (int i = 0; i < 10; i++)
	{
		items[i].price = 500 * (i + 1) * 3;
		items[i].tier = (10 - i);
		items[i].atk = 10 * (i + 1);
	}
	// 함수 포인터를 사용해서
	// tier가 8인 애를 찾아서 출력
	Item* finditem = FindItem_FuncPtr(items, 10, &FineItemPtr_Tier);
	if (finditem != nullptr)
		finditem->PrintItem();

	cout << endl;

	// 함수 객체를 사용해서
	// price가 9000이고 tier가 5 찾아서 출력
	Finder finder;
	finder.itemPrice = 9000;
	finditem = FindItem_Functor(items, 10, finder);
	if (finditem != nullptr)
		finditem->PrintItem();

	cout << endl;


	// 함수 객체를 사용해서
	// price 3000, tier 9, atk 20 찾아서 출력
	
	Finder_All finder_All;
	finder_All.price = 3000;
	finder_All.tier = 9;
	finder_All.atk = 20;
	finditem = FindItem_Functor<Item, Finder_All>(items, 10, finder_All);
	if (finditem != nullptr)
		finditem->PrintItem();

	cout << endl;

	/*finder.itemAtk = 20;
	finditem = FindItem_Functor(items, 10, finder);
	if (finditem != nullptr)
		finditem->PrintItem();*/


	// 함수 객체를 사용해서
	// price 3000, tier 9, atk 20 찾아서 출력
	Finder_Two finder_two;
	finder_two.tier = 9;
	finder_two.atk = 20;
	finditem = FindItem_Functor<Item, Finder_Two>(items, 10, finder_two);
	if (finditem != nullptr)
		finditem->PrintItem();




	return 0;
}