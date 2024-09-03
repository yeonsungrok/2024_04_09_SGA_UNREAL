#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// unordered map;
// ���� :
// - key ������ Ž��(����)�ÿ� ����� �ð��� �ɸ���.
// ���� : 
// - �ؽ��˰��� ������ ���� ���� �� -> ü�̴��� �������.
// -> Ž���� �ð��� �� ���� �ɸ� ���� �ִ�.


// map
// ���� :
// - key ������ Ž�� �ÿ� N���� ���Ұ� ���� ��... logN ��ŭ�� �ð��� �ɸ���.



struct UserInfo
{
	UserInfo() {}
	UserInfo(int id) : id(id) {}

	int id;
};


int main()
{

#pragma region UMap
	//            key,  value
	unordered_map<int, UserInfo> um;

	for (int i = 0; i < 1000; i++)
	{
		// ���������� ���� �ؽ��˰���
		// int key = i % 1000;

		UserInfo info;
		info.id = i;

		pair<int, UserInfo> pair = { i, info };
		um.insert(pair);
	}


	// 3���� ����
	pair<int, UserInfo> myPair = { 4999, UserInfo(4999)};
	um.insert(myPair);

	um.insert(make_pair<int, UserInfo>(5001, UserInfo(5001)));

	um[5000] = UserInfo(5000);
	cout << um[5000].id << endl;

	// �ؽ� �˰���


	//��ȸ
	unordered_map<int, UserInfo>::iterator um_iter;
	for (um_iter = um.begin(); um_iter != um.end(); um_iter++)
	{
		cout << "Key : " << um_iter->first << endl;
		cout << "Value : " <<  um_iter->second.id << endl;
	}


#pragma endregion

	// ����� Ʈ��
	// �ڰ����� ����Ž��Ʈ��
	map<int, UserInfo> myMap;

	for (int i = 0; i < 1000; i++)
	{
		myMap[i] = UserInfo(i);
		myMap.insert(make_pair<int, UserInfo>(i + 1000, UserInfo(i + 1000)));
	}

	map<int, UserInfo>::iterator m_iter = myMap.begin();
	for (m_iter; m_iter != myMap.end(); m_iter++)
	{
		cout << "Key : " << m_iter->first << endl;
		cout << "Value : " << m_iter->second.id << endl;
	}


	return 0;
}