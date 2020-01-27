#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int testcase;
	cin >> testcase;
	
	for (int t = 1; t <= testcase; ++t)
	{
		int num, sum = 0;
		cin >> num;
		
		for (int i = 1; i <= num; i++)
		{
			if (i % 2 == 1) sum += i;
			else sum -= i;
		}
		printf("#%d %d\n", t, sum);
	}
}