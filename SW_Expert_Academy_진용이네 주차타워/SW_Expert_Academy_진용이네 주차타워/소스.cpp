#include<iostream>
#include<queue>
#pragma warning (disable : 4996)
using namespace std;
int parksize, numOfcar;
bool isEmpty_parkingArea(int park[])
{
	bool flag;
	for (int i = 1; i <= parksize; ++i)
		if (park[i] == 0) 
			return flag = true;
	return flag = false;
}

int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		queue<int> q;
		int sum = 0;
		int parkingArea[101] = {0,}; //주차장
		int parkingAreaprice[101]; //i번째 주차공간의 단위 무게당 가격
		int carWeight[2001]; //차량의 무게
		int order[4001];

		cin >> parksize;
		cin >> numOfcar;

		//주차장의 사이즈만큼 i번째 주차공간의 단위 무게당 가격을 입력받음
		for (int i = 1; i <= parksize; ++i)
		{
			scanf("%d", &parkingAreaprice[i]);
		}

		for (int i = 1; i <= numOfcar; ++i)
		{
			scanf("%d", &carWeight[i]);
		}

		for (int i = 1; i <= 2 * numOfcar; ++i)
		{
			int carnum;
			scanf("%d", &carnum);
			order[i] = carnum;
		}

		for (int i = 1; i <= 2 * numOfcar; ++i)
		{
			int curCar = order[i];
			//i번째 순서가 0보다 크면서 주차장이 비어있으면
			if (curCar > 0 && isEmpty_parkingArea(parkingArea))
			{
				//비어 있는 공간 중 가장 빠른 인덱스를 찾아서 차를 댄다.
				for (int j = 1; j <= parksize; ++j)
				{
					if (parkingArea[j] == 0)
					{
						parkingArea[j] = curCar;
						//그리고 차를 대자마자 요금을 징수한다.
						sum += parkingAreaprice[j] * carWeight[curCar];
						break;
					}
				}
			}
			//i번째 순서가 0보다 작으면
			else if (curCar < 0)
			{
				//주차 되어있던 차를 뺀다.
				//그런데 만약 여기서 차를 뺐는데 큐에 대기하던 차가 있다면 그 차를 빼서 빈자리에 바로 집어넣는다.
				for (int j = 1; j <= parksize; ++j)
				{
					if (parkingArea[j] == abs(curCar))
					{
						parkingArea[j] = 0;
						if (!q.empty())
						{
							parkingArea[j] = q.front();
							q.pop();
							sum += parkingAreaprice[j] * carWeight[parkingArea[j]];
							break;
						}
					}
						
				}
			}
			//주차장이 가득차있는데 i번째 순서가 0보다크면
			else if (curCar > 0 && !isEmpty_parkingArea(parkingArea))
			{
				//큐에서 대기한다.
				q.push(curCar);
			}
		}
		printf("#%d %d\n", t, sum);
	}
}