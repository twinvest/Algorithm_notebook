#include<iostream>
#include<algorithm>
#pragma warning(disable : 4996)

using namespace std;
int main()
{
	int n;
	int T;
	int Testcase = 0;
	
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) 
	{
		int ans = 0;
		int dp[1000] = { 0, };
		int arr[1000];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		
		for (int i = 0; i < n; i++) {
			if (dp[i] == 0)
				dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (arr[i] >= arr[j]) {
					if (dp[i] < dp[j] + 1) {
						dp[i] = dp[j] + 1;
						ans = max(ans, dp[i]);
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
			printf("%d ", dp[i]);
		printf("\n");
		printf("#%d %d\n", tc, ans);
	}
}