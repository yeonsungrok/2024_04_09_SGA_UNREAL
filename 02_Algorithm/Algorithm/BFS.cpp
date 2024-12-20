#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
/*
 BFS  // 간선상 최소
 넓이 우선 탐색 (Breadth First Search)

*/

vector<vector<bool>> adjacent;
vector<bool> discovered;
vector<int> parent;

void CreateGraph_AdjacentMatrix()
{


	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][4] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][3] = true;
	adjacent[2][4] = true;
	adjacent[2][5] = true;

	adjacent[3][2] = true;
	adjacent[3][3] = true;

	adjacent[4][0] = true;
	adjacent[4][2] = true;
	adjacent[4][4] = true;
	adjacent[4][6] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;

	adjacent[6][4] = true;
	adjacent[6][6] = true;


}

void BFS(int start)
{
	int N = adjacent.size();
	discovered[start] = true;
	parent[start] = start;

	cout << start << "방문" << endl;

	queue<int> q;
	q.push(start);

	while (true)
	{
		if (q.empty() == true) break;

		int here = q.front();
		q.pop();

		for (int there = 0; there < N; there++)
		{
			if (adjacent[here][there] == false)
				continue;
			if (discovered[there] == true)
				continue;

			q.push(there);
			cout << there << " 발견 !! " << endl;
			discovered[there] = true;
			parent[there] = here;
		}
	}
}

int edgeCont(int start, int dest)
{

	// start 0
	// dest 5
	int result = 0;
	while (true)
	{
		if (dest == start)
			break;

		dest = parent[dest];
		result++;
	}
	return result;
}

int main()
{
	CreateGraph_AdjacentMatrix();

	int size = adjacent.size();
	discovered = vector<bool>(size, false);
	parent = vector<int>(size, -1);

	BFS(0);

	cout << edgeCont(0, 5); // 찾는 길찾기.. 0 에서 5까지

	return 0;
}