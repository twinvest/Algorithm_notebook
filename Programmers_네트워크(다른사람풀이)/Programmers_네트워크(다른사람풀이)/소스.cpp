#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
bool visit[200];

//맨처음엔 단순히 1차원 배열을 사용했다고만 생각했는데 이거 2차원배열 사용했을때하고 1차원배열 사용했을때하고 연산의 횟수가 매우 달라짐.
//1차원 배열에서는 대각선에 있는거 확인할때 진입이 안됨. 예를들어, 0 1 확인하고 1 0 확인할 때!
//근데 2차원 배열에서는 진입됨. 더 문제는 0 1 확인하고 1 0 으로 갔을 때 다시 0 0 으로 간다는 것임.
//물론 1차원이나 2차원이나 이 문제는 통과하긴 함. 그러나, 1차원 배열을 쓰면 메모리적으로나 시간적으로나 우월함.
//테스트케이스 11번에서 0.19ms, 0.5ms로 시간이 출력되는데 0.14ms만큼의 차이가 남.
//인간의 머리로 직관적으로 코드를 이해하기에는 2차원 배열이 더 편한듯.
void dfs(int start, vector<vector<int>>& computers, int n) {
	visit[start] = 1;
	for (int j = 0; j < n; j++)
	{
		if (!visit[j] && computers[start][j] && (start != j) ) //start != j 조건은 내가 문제를 보고 추가함.
			dfs(j, computers, n);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	//n개의 컴퓨터가 있으니까 for문은 n번을 돈다.
	for (int i = 0; i < n; i++)
	{
		//앞에 코드와 다른 점은 2차원 배열대신 visit배열을 1차원으로 사용한 것이다. 또한, 이 visit배열의 i가 컴퓨터의 번호를 의미하기도 한다.
		if (!visit[i]) //만약, i번째 컴퓨터를 방문하지 않았다면
		{
			answer++;
			dfs(i, computers, n);
		}
	}
	return answer;
}

int main()
{
	clock_t start, end;
	vector<vector<int>> arr;
	int N = 3;
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(1);
	t1.push_back(0);

	vector<int> t2;
	t2.push_back(1);
	t2.push_back(1);
	t2.push_back(1);

	vector<int> t3;
	t3.push_back(0);
	t3.push_back(1);
	t3.push_back(1);

	arr.push_back(t1);
	arr.push_back(t2);
	arr.push_back(t3);
	start = clock();
	int ans = solution(N, arr);
	end = clock();
	printf("%d\n", ans);
	printf("%f", end - start);

}