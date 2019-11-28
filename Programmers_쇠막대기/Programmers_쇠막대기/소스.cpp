#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int solution(string arrangement) {
	int ans = 0;
	vector<int> v(arrangement.size(), 0);
	stack<char> s2;
	bool flag = false;
	int len = 0;

	char rem = ')';
	for (int i = 0; i < arrangement.length(); i++)
	{
		// '('인 경우 ==> 스택에 푸쉬푸쉬~~
		if (arrangement[i] == '(')
		{
			s2.push(arrangement[i]);
			printf("%c", s2.top());
			rem = '(';
		}
		// ')'인 경우
		else
		{
			printf("%c", arrangement[i]);
			//레이저임. 왜냐구? 바로 전의 괄호를 rem에 기억시켜놨으니까! 레이저는 -1로 초기화
			if (s2.top() == '(' && rem =='(')
			{
				s2.pop();
				v[i] = -1;
				v[i - 1] = -1;
				rem = ')';
			}
			//막대기의 끝임. 막대기의 끝의 번호를 표시해둔다.
			else if (s2.top() == '(') 
			{
				v[i] = ++len;
				rem = ')';
			}
		}
	}

	//막대기의 첫위치를 찾아가는 반복문
	for (int i = 1; i <= len; i++)
	{
		for(int j=0; j<v.size(); ++j)
		{
			if (v[j] == i)
			{
				for (int k = j; ; --k)
				{
					if (v[k] == 0)
					{
						v[k] = i;
						break;
					}
				}
			}
		}
	}
	
	//절단된 막대기의 개수를 세는 반복문
	int count = 0;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			if (v[j] == i) //시작위치
			{
				int k = j+1;
				while (v[k] != i)
				{
					if (v[k] == -1) count++;
					++k;
				}
				count /= 2;
				ans = ans + 1 + count;
				count = 0;
				break;
			}
		}
	}
	
	printf("\n\n");
	for (int i = 0; i < v.size(); ++i)
	{
		printf("%d ", v[i]);
	}
	printf("\n\n");
	
	return ans;
}

int main()
{
	string s = "()(((()())(())()))(())";
	int ans = solution(s);
	printf("%d", ans);
}