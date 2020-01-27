#include <cstdio>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int N;
int dir[2][2] = { {0, 1}, {1,0} };
bool inside(int y, int x)
{
	return (x >= 0 && x < N) && (y >= 0 && y < N);
}
int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		int arr[15][15];
		int ans;
		cin >> N;
		int lengthofWord;
		cin >> lengthofWord;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%d", &arr[i][j]);
		
		//오른쪽에서 왼쪽으로 검색
		for(int i=0; i<N; ++i)
		{ 
			int count = 0;
			bool flag = false;
			for (int j = 0; j < N; ++j)
			{
				if (arr[i][j] == 1)
				{
					++count;
					flag = true;
				}
				else
				{
					flag = false;
				}
			}
			
		}

	}
}