#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int testcase, a=2, b=3, c=5, d=7, e=11, num;
	int arr[5] = { 2,3,5,7,11 };
	int arr2[5] = { 0, };
	cin >> testcase;
	for (int i = 1; i <= testcase; ++i)
	{
		cin >> num;
		memset(arr2, 0, sizeof(arr2));
		while (num != 1)
		{
			for (int i = 0; i < 5; ++i)
			{
				if (num % arr[i] == 0)
				{
					num /= arr[i];
					++arr2[i];
				}
			}
		}
		printf("#%d %d %d %d %d %d\n", i, arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);
	}
}