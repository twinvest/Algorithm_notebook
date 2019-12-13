#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int solution(vector<vector<int>> jobs) 
{
	int end = 0; int time = 0;

	vector<pair<int, int>> p;
	for (int i = 0; i < jobs.size(); ++i)
		p.push_back(make_pair(jobs[i][0], jobs[i][1]));

	sort(p.begin(), p.end(), compare);
	
	while (!p.empty())
	{
		for (int i = 0; i < p.size(); ++i)
		{
			if (p[i].first <= end)
			{
				end += p[i].second;  //end는 현재 프로세스가 끝나는 점이자 다음 진입할 수 있는 프로세스가 시작되는 점.
				//end에서 기다린 시간(기다린 시간을 명확히 표현하기 위해 괄호를 침)을 더해주고 그것을 time으로 초기화.
				//이 기다린 시간이 음수가 될수도 있음을 생각해보자. 이부분을 생각해내기가 매우 어려웠음. (0 3) (5 1)일때 그림그려놓고 생각해봐~~ 6 + (3 -5) ==> 사실 이거떄문에 level3인듯
				time = end + (time - p[i].first);
				p.erase(p.begin() + i);
				break;
			}
			if (i == p.size() - 1) end++; //비는 시간은 end를 1씩 올려줌. (0 3) (5 1) 이렇게 들어올때 3에서 끝나지만 end를 5까지 올려줘야 첫번째 if문에서 진입가능.
		}
	}
	return time / jobs.size();
}

int main()
{
	vector<vector<int>> v;

	vector<int> v1;
	v1.push_back(0);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(5);
	v2.push_back(1);

	vector<int> v3;
	v3.push_back(8);
	v3.push_back(2);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	int ans = solution(v);
	printf("%d", ans);
}