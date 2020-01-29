#include<cstdio>
#pragma warning (disable : 4996)
int arr[10][10];

void rotate(int arr[][10], int cnt, int N)
{
	if (cnt == 0) return;
	int changed[10][10];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			changed[j][(N - 1) - i] = arr[i][j];

	if (cnt == 1)
	{
		printf("회전 전 배열\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d", changed[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n");
	}
	rotate(changed, --cnt, N);
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int J;
		scanf("%d", &J);
		for (int j = 0; j < J; ++j)
			arr[i][j] = 1;
	}

	rotate(arr, 3, N);

	printf("회전 후 배열\n");
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	//중력처리
	for (int i = 0; i < N; ++i)
	{
		int count = 0;
		for (int j = 0; j < N; ++j)
		{
			if (arr[j][i] == 1)
			{
				++count;
				arr[j][i] = 0;
			}
		}
		int here = N - 1 - count;
		for (int k = N - 1; k > here; --k)
			arr[k][i] = 1;
	}
	printf("\n\n\n");
	printf("중력 발생 후 배열\n");
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}