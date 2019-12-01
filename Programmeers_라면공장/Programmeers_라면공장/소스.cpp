#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int, vector<int>, less<int>> pq;
	int index = 0;

	for (int i = 0; i < k; i++) 
	{
		//일단 받은 날이 되면 전부 pq에 삽입함
		if (dates[index] == i) 
		{
			pq.push(supplies[index]);
			index++;
		}
		//stock이 0이 된날만 pq에서 가장 높은 수를 빼서 추가하고 answer를 ++함
		if (stock == 0) 
		{
			stock = pq.top();
			pq.pop();
			answer++;
		}
		//stock은 매일 1씩 감소
		stock--;
	}
	return answer;
}


int main()
{
	int stock = 4;
	vector<int> dates;
	dates.push_back(4);
	dates.push_back(10);
	dates.push_back(15);

	vector<int> supply;
	supply.push_back(20);
	supply.push_back(5);
	supply.push_back(10);
	int K = 30;
	int ans = solution(stock, dates, supply, K);
	printf("%d", ans);
}