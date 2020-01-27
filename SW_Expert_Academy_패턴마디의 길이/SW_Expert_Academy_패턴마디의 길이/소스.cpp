#include<iostream>
using namespace std;
int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		string tmp;
		int ans = 0;
		cin >> tmp;
		for (int i = 1; i < tmp.size(); ++i)
		{
			string pattern = tmp.substr(0, i);
			string sub = tmp.substr(i, i);
			if (pattern == sub)
			{
				ans = i;
				break;
			}
		}
		printf("#%d %d\n", t, ans);
	}
}