#include <cstdio>
#pragma warning(disable : 4996)
#define A 100000

int main()
{
	char arr[A][8];
	int cnt=0;
	int N=0;
	scanf("%d", &N);
	for (int i = 1; i < N+1; i++) {
		sprintf(arr[i], "%d", i);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 8; j++)
			if (arr[i][j] == '1')
				cnt++;
	printf("%d", cnt);
}