#include<iostream>
using namespace std;
int main()
{
	int N;
	int sum=0;
	cin >> N;
	for (int i = 1000; i >= 1; i /= 10)
	{
		int div = N / i;
		sum += div;
		N = N - (div * i);
	}
	printf("%d", sum);
}