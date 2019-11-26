#include <stdio.h> // 1 1 2 3 5 8 13 21 ...... 
int fibonacci(int x)
{
	if (x == 1)
	{
		return 229;
	}
	if (x == 2)
	{
		return 264;
	}
	return fibonacci(x - 1) + fibonacci(x - 2);
}
int main(void)
{
	printf("%d ", fibonacci(16));
	return 0;
}