#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	for (int i = heights.size(); i > 0; --i)
	{
		bool flag = true;
		int num = heights.at(i - 1);
		for (int j = i - 2; j >= 0; --j)
		{
			if (num < heights.at(j))
			{
				answer.push_back(j + 1);
				flag = false;
				break;
			}
		}
		if (flag) answer.push_back(0);
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	vector<int> ans = solution(v);
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%d ", ans.at(i));
	}
}