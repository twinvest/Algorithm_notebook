#include <iostream>
#include <algorithm>
using namespace std;
int solve(int* ARR, int MAX, int SIZE)
{
	int ret = 0, temp;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = SIZE - 1; j > i; j--)
		{
			if (ARR[i] + ARR[j] <= MAX) {
				temp = ARR[i] + ARR[j];
				if (temp > ret)
					ret = temp;
				if (ret == MAX) {
					return ret;
				}
			}
		}
	}
	if (ret == 0)
		return -1;
	else
		return ret;

}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int TC, N, M;
	cin >> TC;
	for (int t = 1; t <= TC; t++)
	{
		cin >> N >> M;
		int* ARR = new int[N];
		for (int i = 0; i < N; i++)
			cin >> ARR[i];
		sort(ARR, ARR + N);
		cout << "#" << t << ' ' << solve(ARR, M, N) << '\n';
	}
	return 0;
}