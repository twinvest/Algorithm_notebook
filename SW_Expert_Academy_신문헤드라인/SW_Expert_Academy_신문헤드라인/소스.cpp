#include<iostream>
#include<string>
using namespace std;
int main()
{
	string tmp;
	cin >> tmp;
	for (int i = 0; i < tmp.size(); ++i)
	{
		if (tmp[i] >= 97 && tmp[i] <= 122)
			tmp[i] = tmp[i] - 32;
	}
	cout << tmp;
}