#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
bool friends[10][10];
bool student[10];
int N, M;
void init() {
	for (int i = 0; i < 10; i++)
	{
		student[i] = false;
		for (int j = 0; j < 10; j++)
		{
			friends[i][j] = false;
		}
	}
}

int search() {
	int first = -1;
	for (int i = 0; i < N; ++i) {
		if (student[i] == false) {
			first = i;
			//student[i] = true;
			break;
		}
	}
	if (first == -1) return 1;
	int ret = 0;
	for (int i = first + 1; i < N; i++)
	{
		if (!student[i] && friends[first][i]) {
			student[first] = student[i] = true;
			ret += search();
			student[first] = student[i] = false;
		}
	}
	return ret;
}
int main(void)
{
	int testcase;
	scanf("%d", &testcase);
	while (testcase-- > 0) {
		int ret = 0;
		init();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			int tmp1, tmp2;
			scanf("%d %d", &tmp1, &tmp2);
			friends[tmp1][tmp2] = true;
			friends[tmp2][tmp1] = true;
		}
		ret = search();
		printf("%d\n", ret);
	}
}