#include<iostream>
using namespace std;
int main()
{
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31,31,30,31,30,31 };
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; ++t)
	{
		int M, D, nextM, nextD, sum=0;
		cin >> M;
		cin >> D;
		cin >> nextM;
		cin >> nextD;

		if (nextM - M == 0)
			sum = nextD - D + 1;
		else
		{
			sum = arr[M - 1] - D;
			for (int i = 0; i < nextM - M -1; ++i)
				sum += arr[M + i];
			sum += nextD+1;
		}
		printf("#%d %d\n", t, sum);
	}
}