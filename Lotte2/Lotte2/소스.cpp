#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

bool solution(vector<string> phoneBook) {
	bool answer = true;
	sort(phoneBook.begin(), phoneBook.end());

	for (int i = 0; i < phoneBook.size() - 1; i++)
	{
		if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
		{
			answer = false;
			break;
		}
	}
	return answer;
}

int main()
{
	int testcase;
	int numofphone;
	
	scanf("%d", &testcase);
	scanf("%d", &numofphone);
	vector<string> v(numofphone);
	while (testcase--)
	{
		for (int i = 0; i < numofphone; ++i)
		{
			cin >> v[i];
		}
		bool ans = solution(v);

		if (!ans)
			printf("NO");
		else
			printf("YES");
	}
}