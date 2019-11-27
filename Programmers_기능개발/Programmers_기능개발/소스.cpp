#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> ans;
	queue<int> q;
	int count = 0;
	
	//실제 완성 일수를 구하는 반복문
	for (int i = 0; i < progresses.size(); ++i)
	{
		int day = 0;
		int cur = progresses.at(i);
		while (1)
		{
			if (cur >= 100)
			{
				q.push(day);
				break;
			}
			cur += speeds.at(i);
			++day;
		}
	}

	//큐에서 제일 앞 날짜 하나를 뽑아내고 이것보다 큰 숫자가 나올때까지 count를 ++함
	int cur = q.front();
	q.pop();
	++count;
	while (!q.empty())
	{
		if (cur >= q.front())
		{
			++count;
			q.pop();
		}
		else
		{
			ans.push_back(count);
			count = 0;
			cur = q.front();
			q.pop();
			++count;
		}
	}
	ans.push_back(count);
	return ans;
}

int main()
{
	vector<int> ans;
	vector<int> progress;
	vector<int> speed;
	progress.push_back(10);
	progress.push_back(1);

	speed.push_back(2);
	speed.push_back(1);

	ans = solution(progress, speed);
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%d ", ans.at(i));
	}
}