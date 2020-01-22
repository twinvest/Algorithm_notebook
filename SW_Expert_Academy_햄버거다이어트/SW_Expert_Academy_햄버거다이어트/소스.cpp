#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define MIN -987654321
using namespace std;
int cals[20], scores[20];
int testcase, N, limit, maxim, ans;
int solve(int idx, int score, int cal)
{
	if (cal > limit) return -1;
	if (idx == N)
	{
		if (maxim < score) maxim = score;
		return maxim;
	}
	return max(solve(idx + 1, score + scores[idx], cal + cals[idx]), solve(idx + 1, score, cal));
}
int main()
{
	
	cin >> testcase;
	for (int i = 1; i <= testcase; ++i)
	{
		memset(cals, 0, sizeof(cals));
		memset(cals, 0, sizeof(scores));
		cin >> N;
		cin >> limit;
		maxim = MIN;
		for (int j = 0; j < N; ++j)
		{
			cin >> scores[j];
			cin >> cals[j];
		}
		ans = solve(0, 0, 0);
		printf("#%d %d\n", i, ans);
	}
}