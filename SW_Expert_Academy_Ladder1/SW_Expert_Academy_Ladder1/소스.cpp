#include<iostream>
using namespace std;
int arr[100][100];
int dir[3][2] = { {0, -1}, {0, 1}, {-1, 0} };

bool inside(int y, int x)
{
	return (y >= 0 && y < 100) && (x >= 0 && x < 100);
}

int main()
{
	int testcase, ans, curx, cury, nextx, nexty;
	for (int t = 1; t <= 10; t++)
	{
		cin >> testcase;
		if (testcase == t)
		{
			//입력받기
			for (int i = 0; i < 100; ++i)
				for (int j = 0; j < 100; ++j)
					scanf("%d", &arr[i][j]);

			//2인곳 찾기
			for (int i = 0; i < 100; ++i)
			{
				if (arr[99][i] == 2)
				{
					curx = i;
					cury = 99;
				}
			}

			//한칸씩 위로가는데
			for (int i = 99; i >= 0; --i)
			{
				//올라갈때 마다 3방향을 훑어준다. 왼쪽, 오른쪽, 위(이때 위를 제일 늦게 훑는다.)
				for (int j = 0; j < 3; ++j)
				{
					int nextx = curx + dir[j][1];
					int nexty = cury + dir[j][0];

					//마지막 nexty가 -1에 도달했을 때 예외상황 처리
					if (nexty == -1)
						nexty = 0;

					//범위 벗어나면 쌩깜
					if (!inside(nexty, nextx))
						continue;

					//범위를 벗어나지 않았으면 3가지 중 하나를 선택함.
					//왼쪽이나 오른쪽일 때
					if (j == 0 || j == 1)
					{
						if (arr[nexty][nextx] == 1)
						{
							arr[cury][curx] = 3;
							curx = curx + dir[j][1];
							cury = cury + dir[j][0];
							++i;
							break;
						}
					}
					//위로갈때
					else
					{
						if (arr[nexty][nextx] == 1)
						{
							arr[cury][curx] = 3;
							curx = curx + dir[j][1];
							cury = cury + dir[j][0];
						}
					}
				}
			}

			//0행을 훑어서 3이 있으면 그게 정답
			for (int i = 0; i < 100; ++i)
				if (arr[0][i] == 3)
					ans = i;
			printf("#%d %d\n", t, ans);
		}
	}
}