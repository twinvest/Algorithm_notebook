#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int st1[5] = { 1,2,3,4,5 };
	int st2[8] = { 2,1,2,3,2,4,2,5 };
	int st3[10] = { 3,3,1,1,2,2,4,4,5,5 };

	int cnt[3] = { 0, };
	for (int i = 0; i < answers.size(); ++i)
	{
		if (answers[i] == st1[i % 5]) ++cnt[0];
		if (answers[i] == st2[i % 8]) ++cnt[1];
		if (answers[i] == st3[i % 10]) ++cnt[2];
	}
	int high = cnt[0];
	for (int i = 0; i < 3; ++i)
		if (high < cnt[i])
			high = cnt[i];

	for (int i = 0; i < 3; ++i)
		if (high == cnt[i])
			answer.push_back(i + 1);
	return answer;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(2);
	vector<int> ans = solution(v);
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);

}