#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int dist[15][15];

//len은 지금까지 만든 경로의 길이
int TSP(vector<int> path, vector<bool> visited, int len) 
{
	//모든 도시를 다 방문했을 경우
	if (path.size() == n) return len + dist[path.back()][0];
	int ret = 987654321;

	for (int next = 0; next < n; next++) {
		//방문 했다면 다시 첨으로
		if (visited[next] == true) continue;

		int cur = path.back();
		path.push_back(next);
		visited[next] = true;
		ret = min(ret, TSP(path, visited, len + dist[cur][next]));
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
		}
	}

	vector<int> path(1, 0); //경로를 저장할 벡터.
	vector<bool> visited(n, false); //방문 여부를 저장할 벡터. false로 초기화
	visited[0] = true; //출발 도시 방문여부 체크
	double ret = TSP(path, visited, 0);
	cout << ret << endl;
}