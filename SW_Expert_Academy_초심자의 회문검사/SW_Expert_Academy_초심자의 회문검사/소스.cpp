#include<iostream>
using namespace std;
int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		bool ans;
		string palin;
		cin >> palin;
		for (int i = 0; i < palin.size() / 2; ++i)
		{
			if (palin[i] == palin[palin.size() - 1 - i]) ans = true;
			else ans = false;
		}
		if (ans) printf("#%d %d\n", t, 1);
		else printf("#%d %d\n", t, 0);
	}
}