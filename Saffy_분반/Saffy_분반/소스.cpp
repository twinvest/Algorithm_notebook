#include<iostream>
int a[6][6] = {0,};
int main()
{
	a[1][1] = 1;
	printf("%d \n", a[1][1]);

	int i, j;
	for (i = 2; i < 6; i++)
	{
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i-1][j-1]+a[i-1][j];
			printf("%d", a[i][j]);

		}
		printf("\n");
	}
}