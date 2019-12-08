#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
#pragma warning(disable : 4996)
#define MAX 25

using namespace std;
int arr[MAX][MAX];
int visit[MAX][MAX] = {false, };
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } }; //위 밑 오른쪽 왼쪽
int N; //배열의 범위를 의미하는 N
int danji = 0;
vector<int> ans_vector; //정답들 여기다 집어넣은 다음에 정렬할거임.

//내부범위 만족
bool inside(int m, int n) 
{
	return (n >= 0 && n < N) && (m >= 0 && m < N);
}

//탐색코드 dfs
int dfs(int arr[MAX][MAX], int y, int x)
{
	int count = 0;
	//1이면 방문해야함
	if (arr[y][x] == 1)
	{
		count++;                //count올리고
		visit[y][x] = true;     //방문배열 true로 만들어줌
	}
		
	//4방향탐색
	for (int i = 0; i < 4; i++)
	{
		//다음 검색할곳
		int nx = x + dir[i][0], ny = y + dir[i][1];
		//범위 벗어나면 continue
		if (!inside(nx, ny)) continue;
		//1인데 아직 방문하지 않은 곳임 ==>탐색해야함!!
		else if (arr[ny][nx] == 1 && visit[ny][nx] == false)
		{
			int ret = dfs(arr, ny, nx);
			count += ret;  //반환값은 count에 더해줘야쥐~~dfs니까!
		}
	}
	return count;
}

int main() {
	
	scanf("%d", &N);
	//입력부
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			scanf("%d", &arr[i][j]);

	//탐색시작
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (arr[i][j] == 1 && visit[i][j] == false)
			{
				++danji;
				int ans = dfs(arr, i, j);
				ans_vector.push_back(ans);
			}

		}
	}
	
	printf("%d\n", danji);
	//정답 벡터정렬
	sort(ans_vector.begin(), ans_vector.end());
	for (int i = 0; i < ans_vector.size(); ++i)
	{
		printf("%d\n", ans_vector[i]);
	}

}