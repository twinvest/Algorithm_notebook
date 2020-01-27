#include<cstdio>
#include<iostream>
#include<algorithm>
using  namespace std;
int Bfunc(int Q, int R, int S, int W)
{
	//기본요금을 초과한 경우
	if (W > R) return Q + ((W - R) * S);
	return Q;
}

int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		int P, Q, R, S, W;
		cin >> P;
		cin >> Q;
		cin >> R;
		cin >> S;
		cin >> W;

		int A, B, ans;		
		A = P * W;
		B = Bfunc(Q, R, S, W);
		ans = min(A, B);
		printf("#%d %d\n", t, ans);
	}
}