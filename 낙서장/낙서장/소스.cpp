#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	queue<pair<int, int>> q;
	priority_queue<int> pq;

	int answer = 0;

	//큐와 우선순위 큐를 만든다.
	for (int i = 0; i < priorities.size(); ++i)
	{
		q.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}
	
	while (!q.empty())
	{
		if (q.front().second == pq.top())
		{
			if (q.front().first == location)
			{
				return answer + 1;
			}
			else
			{
				++answer;
				q.pop();
				pq.pop();
			}
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
	}
	return answer;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(9);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	int ans = solution(v, 0);
	printf("%d", ans);
}