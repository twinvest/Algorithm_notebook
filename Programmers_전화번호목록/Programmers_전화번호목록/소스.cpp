#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> v;

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
	v.push_back("119");
	v.push_back("97674223");
	v.push_back("1195524421");
	bool ans = solution(v);
}