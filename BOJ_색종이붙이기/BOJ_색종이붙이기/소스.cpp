#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define N 11
#define INF 987654321
using namespace std;

int map[N][N], ans = INF;
bool visited[N][N];

int paperCnt[6];//각 색종이를 사용한 횟수를 저장 

typedef pair<int, int> pp;
vector<pp> fillSpace;

bool check(int x, int mx, int y, int my) {
	//mx, my는 max_x, max_y의 줄임으로 사용 
	if (mx > N - 1 || my > N - 1) return false;

	for (int i = x; i < mx; i++) {
		for (int j = y; j < my; j++) {
			if (visited[i][j]) return false;
			if (!map[i][j]) return false;
		}
	}
	return true;
}
//cnt는 사용한 색종이의 개수, fill은 채운칸의 수
void dfs(int cnt, int fill) {
	if (fill == fillSpace.size()) 
	{
		ans = min(ans, cnt);
		return;
	}
	if (ans <= cnt) return; //이미 최대값을 넘어버림

	//5*5부터 차례대로 들어갈 수 잇는 곳을 채워간다.
	for (int i = 0; i < fillSpace.size(); i++) 
	{
		int x = fillSpace[i].first;
		int y = fillSpace[i].second;

		if (visited[x][y]) continue; //이미 채워진 칸 

		for (int j = 5; j > 0; j--) 
		{
			if (paperCnt[j] > 4) {
				//최대 5장까지만 사용 가능 
				continue; //다른 색종이 사용
			}

			int nx = x + j;
			int ny = y + j; //5*5 , 4*4 ... 이기 때문에 j만큼 늘려준다.

			if (check(x, nx, y, ny)) 
			{
				//j종류의 색종이로 채워질 수 있는 공간이라면
				for (int k = x; k < nx; k++) 
				{
					for (int z = y; z < ny; z++) 
					{
						visited[k][z] = true; //방문 표시->채웠다는 의미
					}
				}
				paperCnt[j]++; //색종이 하나 씀 

				dfs(cnt + 1, fill + j * j); //j*j만큼 채웠음 

				///////////백트래킹////////////////////
				for (int k = x; k < nx; k++) 
				{
					for (int z = y; z < ny; z++) 
					{
						visited[k][z] = false; //방문 표시->채웠다는 의미
					}
				}
				paperCnt[j]--;
				///////////백트래킹////////////////////
			}
		}
		return;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			cin >> map[i][j];
			if (map[i][j]) fillSpace.push_back(pp(i, j));
		}
	}
	//input 
	dfs(0, 0); //색종이를 사용한 횟수, 채운 칸의 수 

	if (ans == INF) ans = -1;
	cout << ans << '\n';
	return 0;
}