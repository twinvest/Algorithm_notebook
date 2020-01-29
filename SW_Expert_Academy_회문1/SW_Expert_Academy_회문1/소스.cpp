#include<iostream>
#include<string>
#pragma warning (disable : 4996)
using namespace std;
int main()
{
	for (int t = 1; t <= 10; ++t)
	{
		char arr[8][8];
		int length, ans = 0;
		scanf("%d", &length);

		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				scanf("%c", &arr[i][j]);

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8 - length +1; ++j)
			{
				bool flag = false;
				string palin = "";
				for (int k = j; k < j + length; ++k)
				{
					palin += to_string(arr[j][k]);
				}

				for (int k = 0; k < length / 2; ++k)
				{
					if (palin[k] == palin[palin.size() - 1 - k]) flag = true;
					else flag = false;
				}
				if (flag) ++ans;
			}
		}
		printf("%d\n", ans);
	}
}