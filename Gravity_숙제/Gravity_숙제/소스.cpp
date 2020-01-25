#include<cstdio>
#pragma warning (disable : 4996)
int arr[10][10];
int copy[10][10];
void reverse(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			copy[j][4 - i] = arr[i][j];
		}
	}
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

	for (int i = 0; i < 2; ++i)
		reverse(N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d", copy[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

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
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

}