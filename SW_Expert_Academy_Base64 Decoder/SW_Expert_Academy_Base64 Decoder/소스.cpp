#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

int tenConvertTwo(int num)
{
	int result = 0;
	for (int i = 1; num > 0; i *= 10)
	{
		int binary = num % 2;
		result += binary * i;
		num /= 2;
	}
	return result;
}

int twoConvertTen(int num)
{
	int result = 0, mul = 1;
	while (num > 0)
	{
		if (num % 2)
			result += mul;
		mul *= 2;
		num /= 10;
	}
	return result;
}

int main()
{

	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		vector<string> v6;
		vector<string> v24;
		vector<int> ans;
		
		int buffer[100000];
		char source[64] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
		'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
		'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0',
		'1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };
		
		string s;
		cin >> s;

		//buffer에다가 해당숫자를 집어넣음.
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = 0; j < 64; ++j)
			{
				if (s[i] == source[j])
				{
					buffer[i] = j;
					break;
				}
			}
		}

		//2진수만들기 알고리즘
		for (int i = 0; i < s.size(); ++i)
		{
			string tmp = to_string(tenConvertTwo(buffer[i]));
			while (1)
			{
				if (tmp.size() == 6)
				{
					v6.push_back(tmp);
					break;
				}
				else
					tmp = "0" + tmp;
			}
		}

		// 6 to 24
		for (int i = 0; i < v6.size(); i += 4)
		{
			string tmp = v6[i] + v6[i + 1] + v6[i + 2] + v6[i + 3];
			v24.push_back(tmp);
		}

		//24 to 8
		for (int i = 0; i < v24.size(); ++i)
		{
			string tmp = v24[i];
			int tmp1 = twoConvertTen(stoi(v24[i].substr(0, 8)));
			int tmp2 = twoConvertTen(stoi(v24[i].substr(8, 8)));
			int tmp3 = twoConvertTen(stoi(v24[i].substr(16, 8)));

			ans.push_back(tmp1);
			ans.push_back(tmp2);
			ans.push_back(tmp3);
		}
		
		printf("#%d ", t);
		for (int i = 0; i < ans.size(); ++i)
			printf("%c", ans[i]);
		printf("\n");
	}
}