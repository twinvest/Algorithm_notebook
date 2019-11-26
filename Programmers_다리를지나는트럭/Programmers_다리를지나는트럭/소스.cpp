#include <string>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int weight_now = 0;
	queue<int> times, entered_weights;
	for (int i = 1;; i++)
	{
		if (times.size() > 0)
		{
			// 다리의 맨 앞에 있던 트럭이 다리를 다 건넜을 때
			if (i - times.front() == bridge_length)
			{
				// 트럭이 다리를 다 건널 때 마다 도착한 시간을(출발한 시간 + 다리 길이) 갱신해준다.
				int finish_time = bridge_length + times.front();
				// 다 건넌 트럭의 정보를 삭제해주고 다리가 견디는 무게도 갱신한다.
				times.pop();
				weight_now -= entered_weights.front();
				entered_weights.pop();
				//건너야할 트럭이 더 이상 없고 건너는 중인 트럭도 없을 때
				if (truck_weights.size() == 0 && entered_weights.size() == 0)
				{
					//마지막 트럭이 들어간 시간을 리턴한다.
					return finish_time;
				}
			}
		}
		//다리의 한계 하중치를 초과하기 전까지 트럭을 다리 위로 올린다.
		while (1)
		{
			// 다리에 트럭이 더 들어서지 못하거나 더 이상 들어설 트럭이 없으면 break
			if (truck_weights.size() == 0 || weight_now + truck_weights.front() > weight)
			{
				break;
			}
			else {
				// 다리에 들어온 트럭의 무게가 추가된다.
				weight_now += truck_weights.front();
				// 다리에 들어온 트럭의 무게와 들어온 시간을 기록한다.
				entered_weights.push(truck_weights.front());
				times.push(i);
				truck_weights.erase(truck_weights.begin());
				break;
			}
		}

	}
}
int main()
{
	vector<int> v;
	
	int bridge_length = 2;
	int weight = 10;
	
	v.push_back(7);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	int ans = solution(bridge_length, weight, v);
	printf("%d", ans);
}