#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Item
{
	Item(int price, int tier, int atk) : price(price), tier(tier), atk(atk) {}

	int price;
	int tier;
	int atk;
};

// 람다 함수
// [] () -> {}
// [캡쳐 : 외부 변수를 복사해서 사용하는 부분]
// (매개변수)
// -> 반환 자료형
// {함수식}


int main() 
{
	srand(time(nullptr));

	vector<Item*> items;

	for (int i = 0; i < 10; i++)
	{
		int tier = rand() % 10;
		Item* item = new Item(tier * 100, tier, tier * 5);

		items.push_back(item);

	}

	struct itemFinder_Tier
	{
		bool operator()(Item* item)
		{
			if (item->tier == tier)
				return true;
			return false;
		}
		int tier;
	};

	itemFinder_Tier finder;
	finder.tier = 0;



	// Call able 객체
	items.erase(std::remove_if(items.begin(), items.end(), finder), items.end());

	// -----------------------------------------

	int capture = 1;
	//int* capture_ptr = new int(1);    // = : 위에 있는 지역변수를 모두 캡쳐해간다.

	items.erase(std::remove_if(items.begin(), items.end(), [capture](const Item* item) -> bool   // [capture]
	{
			if (item->tier == 0)  
				return true;
			return false;

	}), items.end());



	// Items를 가격순으로 내림차순으로 정렬해주세요.

	std::sort(items.begin(), items.end(), [](Item* a, Item* b) -> bool 
		{
			if (a->price > b->price)
				return true;
			return false;
		});

	



	return 0;
}