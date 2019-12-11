#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<bool>> visit;

void dfs(int start, vector<vector<int>>& computers, int n) 
{
	//start는 solution에서 첫 재귀 호출한 곳의 컴퓨터 넘버이자. 두번째 재귀호출부터는 j로 변경되면서 연결된 컴퓨터를 모두 찾게 해주는 역할.
	//만약, 전부 연결되어 있다면 solution에서 첫번째 재귀호출 후 start가 계속 j로 변하면서 연결된 모든 컴퓨터를 찾을것이다.
	for (int j = 0; j < n; j++)
	{
		if (computers[start][j] == 1 && !visit[start][j])
		{
			visit[start][j] = true;
			dfs(j, computers, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	//2차원벡터에 size부여
	visit.assign(n, vector<bool>(n, 1));
	//2차원 벡터 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = false;


	int answer = 0;
	//탐색시작
	for (int i = 0; i < n; i++)
	{
		//i는 하나의 컴퓨터를 의미한다고 생각해라. 예를 들어, 첫번째 테스트케이스인 [2][2]의 세번째 컴퓨터를 탐색할 때 이 코드는 매우 유용함.
		if (!visit[i][i])
		{
			answer++;
			dfs(i, computers, n);
		}
	}
	return answer;
}

int main()
{
	vector<vector<int>> arr;
	int N = 3;
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(1);
	t1.push_back(0);

	vector<int> t2;
	t2.push_back(1);
	t2.push_back(1);
	t2.push_back(0);

	vector<int> t3;
	t3.push_back(0);
	t3.push_back(0);
	t3.push_back(1);

	arr.push_back(t1);
	arr.push_back(t2);
	arr.push_back(t3);



	int ans = solution(N, arr);
	printf("%d", ans);


}