#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// LIS (Longest Increasing Subsequence)
// 최장 증가 부분 수열
// 수열 = 숫자를 나열하는 것

vector<int> v = { 5, 6, 7, 1, 2, 3, 4 };   //3, 5, 7, 9, 1, 4, 8
// 증가 부분 수열 : 점점 증가되는 부분 수열
// 최장 증가 부분 수열 : 증가 부분 수열 중에 가장 긴 것

// Lis(4) : 1
// Lis(3) .... v[3] <= v[next] -> : 2
// Lis(2) .... v[2] <= v[3] ->  / v[2] <= v[4] -> 2
// Lis(1) .... Lis(2) + 1 / Lis(3) +1 / Lis(4) +1

vector<int> cache; // 계산시 v[3] 계속 확인함...이럴때 메모제이션 사용..

int Lis(int pos)
{
	//기저사항
	if (pos == v.size() - 1)
		return 1;

	// 메모이제이션
	int& ref = cache[pos];
	if (ref != -1)
		return ref;

	ref = 1;
	for (int next = pos + 1; next < v.size(); next++)
	{
		if (v[pos] <= v[next])
		{
			ref = max(ref, Lis(next) + 1);
		}
	}

	return ref;
}


int main()
{
	cache = vector<int>(v.size(), -1);
	int lis = 1;

	for (int i = 0; i < v.size(); i++)
	{
		lis = max(lis, Lis(i));
	}

	cout << lis << endl;



	return 0;
}