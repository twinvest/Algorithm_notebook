#include<iostream>
#include<vector>
#include<algorithm>

#pragma warning(disable : 4996)
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		vector<int> v;
		int sum = 0, N, M, gap;
		cin >> N;
		cin >> M;
		int arr1[20];
		int arr2[20];

		for (int i = 0; i < N; ++i)
			scanf("%d", &arr1[i]);
		for (int i = 0; i < M; ++i)
			scanf("%d", &arr2[i]);

		gap = abs(N - M) + 1;
		int min1 = min(N, M);
		for (int j = 0; j < gap; ++j)
		{
			sum = 0;
			for (int k = 0; k < min1; ++k)
			{
				if (N > M)
				{
					int mul = arr1[j + k] * arr2[k];
					sum += mul;
				}
				else if(N < M)
				{
					int mul = arr1[k] * arr2[j+k];
					sum += mul;
				}
				else if (N == M)
				{
					int mul = arr1[k] * arr2[k];
					sum += mul;
				}

			}
			v.push_back(sum);
		}
		sort(v.begin(), v.end(), greater<int>());
		printf("#%d %d\n", t, v[0]);
	}
}