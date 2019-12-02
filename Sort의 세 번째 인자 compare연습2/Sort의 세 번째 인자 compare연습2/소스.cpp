#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

//3개 중 2개를 비교. 만약, 점수가 같을시에 나이가 더 어린놈이 우선순위가 높다.
bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
	if (a.second.first == b.second.first)
	{
		return a.second.second < b.second.second;
	}
	else
		return a.second.first > b.second.first;
}


int main()
{
	vector<pair<string, pair<int, int>>> v;
	v.push_back(make_pair("김태우", make_pair(90, 26)));
	v.push_back(make_pair("류지훈", make_pair(90, 27)));
	v.push_back(make_pair("엄유진", make_pair(80, 25)));
	v.push_back(make_pair("정진우", make_pair(70, 26)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); ++i)
	{
		cout << "이름 : " + v[i].first << "   점수 : " << v[i].second.first << endl;
	}
}