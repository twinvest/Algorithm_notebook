#include <string>
#include <vector>

using namespace std;
static int answer = -1;

int increment(int value, int N)
{
	return value * 10 + N;
}

//cnt는 깊이를 의미. 깊이는 숫자가 사용된 개수를 의미.
void dfs(int N, int number, int cnt, int prev)
{
	int temp_N = N;
	//문제 조건에 따라 8번 이상 깊이가 들어갔는데(5를 사용했는데) 찾아내지 못한다면 -1을 리턴
	if (cnt > 8)
	{
		answer = -1;
		return;
	}
	//prev가 number와 같다는 말은 dfs를 실행하면서 사칙연산을 수행하던 어느 순간 prev가 number와 같아지는 경우를 찾았단 말임.
	if (number == prev)
	{
		//그때 answer == -1 조건은 처음으로 answer가 초기화 되는 순간이고, answer>cnt 조건을 만족하면 기존의 answer보다 더 짧게 N을 사용해서 원하는 number를 만들어낸것임.
		if (answer == -1 || answer > cnt)
			answer = cnt;
		return;
	}
	//이 부분이 이 문제의 핵심코드임. for문에서 자체에서 깊이(cnt)를 조절하고 있고 인자로 cnt + i + 1을 넘기는게 인상적.
	for (int i = 0; i < 8 - cnt; i++)
	{
		dfs(N, number, cnt + i + 1, prev - temp_N);
		dfs(N, number, cnt + i + 1, prev + temp_N);
		dfs(N, number, cnt + i + 1, prev * temp_N);
		dfs(N, number, cnt + i + 1, prev / temp_N);
		
		//모든 dfs를 돌고와서 다시 제 자리. 5면 55로 2면 22로 temp_N을 초기화. 
		//이 코드가 실행된 후 for문의 i는 0에서 1로 증가되면서 cnt를 즉 깊이를 하나 올린효과를 낼 수 있음.
		temp_N = increment(temp_N, N); 
	}
}

int solution(int N, int number) {
	dfs(N, number, 0, 0);
	return answer;
}

int main()
{
	int N = 5;
	int number = 12;
	int ans = solution(N, number);
	printf("%d", ans);
}