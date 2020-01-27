#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; ++t)
	{
		int ans = 0;
		bool flag = true;
		bool arr[10] = {false, };
		int index;
		cin >> index;
		
		int sum = index;
		while (flag)
		{
			flag = false;
			string tmp = to_string(sum);
			char ch;
			
			for (int i = 0; i < tmp.size(); ++i)
			{
				ch = tmp[i] - 48;	
				arr[ch] = true;
			}

			++ans;
			sum += index;

			for (int i = 0; i < 10; ++i)
			{
				if (arr[i] == false)
				{
					flag = true;
					break;
				}
			}
		}
		printf("#%d %d\n", t, ans*index);
	}
}