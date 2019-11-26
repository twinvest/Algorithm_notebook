#include<iostream>
int main()
{
	int tmp;
	int sum = 0;
	int f1 = 1, f2 = 1;
	while (f1 + f2 <= 4000000) {
		tmp = f1 + f2;
		if (tmp % 2 == 0) sum += tmp;
		f1 = f2;
		f2 = tmp;
	}
	std::cout << sum;
}