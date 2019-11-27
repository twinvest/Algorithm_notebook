#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> q;
	int sum, count; sum = count = 0;
	for (int i = 0; i < truck_weights.size(); i++) {
		int d = truck_weights[i];
		while (true) 
		{
			if (q.empty()) 
			{
				q.push(d);
				count++;
				sum += d;
				break;
			}
			//다리의 길이를 이렇게 표현. 올라갈 수 있는 차가 없는 경우
			else if (q.size() == bridge_length)  
			{
				sum -= q.front(); 
				q.pop();
			}
			//다리 위에 올라갈 수 있는 차의 공간이 있는 경우
			else 
			{
				//무게를 따져보는데, 무게 초과인 경우. 더미데이터(0)를 하나 넣어준다(이는 차가 한칸 이동하는 효과임)
				if (sum + d > weight) 
				{
					q.push(0);
					count++;
				}
				//무게가 초과하지 않은 경우. 차를 올린다.
				else
				{
					q.push(d);
					count++;
					sum += d;
					break;
				}
			}
		}
	}
	return count + bridge_length;
}

int main()
{
	int bridge_length = 2;
	int weight = 10;
	vector<int> v;
	v.push_back(7);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	int ans = solution(bridge_length, weight, v);
	printf("%d", ans);
}