#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first > b.first;
}

int main()
{
	vector<pair<int, string>>  v;
	v.push_back(make_pair(90, "김태우"));
	v.push_back(make_pair(85, "엄유진"));
	v.push_back(make_pair(50, "류지훈"));
	v.push_back(make_pair(92, "나길주"));
	v.push_back(make_pair(75, "정진우"));
	
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i<v.size(); ++i)
	{
		cout <<"점수 : " << v[i].first << "   이름 : " + v[i].second <<endl;
	}
}