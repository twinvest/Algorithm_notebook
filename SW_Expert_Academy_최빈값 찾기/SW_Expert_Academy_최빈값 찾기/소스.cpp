#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#define MIN -987654321
#pragma warning(disable : 4996 )
using namespace std;
int student[1000];
int check[101];
int main()
{
	int ans, ans2, testcase, caseNum;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		memset(student, 0, sizeof(student));
		memset(check, 0, sizeof(check));
		cin >> caseNum;
		if (caseNum == t)
		{
			ans = MIN;
			for (int i = 0; i < 1000; ++i)
			{
				scanf("%d", &student[i]);
				++check[student[i] + 1];
			}

			for (int i = 0; i <= 100; ++i)
			{
				if (ans <= check[i])
				{
					ans = check[i];
					ans2 = i;
				}
			}
		}
		printf("#%d %d\n", t, ans2 - 1);
	}
}