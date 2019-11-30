#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	//pq 오름차순 선언
	priority_queue<int, vector<int>, greater<int>> pq;
	
	//pq에 전부삽입
	for (int i = 0; i < scoville.size(); ++i)
		pq.push(scoville[i]);
	
	//pq에서 두개 빼서 하나 생성하는 과정
	while (1)
	{
		if (pq.top() >= K) break;
		if (pq.size() == 1)
		{
			answer = -1;
			break;
		}
		answer++;
		int n1 = pq.top(); pq.pop();
		int n2 = pq.top(); pq.pop();
		int new_sco = n1 + (n2 * 2);
		pq.push(new_sco);
	}
	return answer;
}


int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(9);
	v.push_back(10);
	v.push_back(12);
	int k = 1000000000;

	int ans = solution(v, k);
	printf("%d", ans);
}