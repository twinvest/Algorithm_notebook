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
			if (s2.top() == '(' && rem =='(') //레이저임
			{
				s2.pop();
				v[i] = -1;
				v[i - 1] = -1;
				rem = ')';
			}
			else if (s2.top() == '(') //막대기의 끝임
			{
				v[i] = ++len;
			}
		}
	}

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
	
	/*
	printf("\n\n");
	printf("%d", v.size());
	printf("\n\n");
	for (int i = 0; i < v.size(); ++i)
	{
		printf("%d ", v[i]);
	}
	printf("\n\n");
	*/
	return ans;
}

int main()
{
	string s = "()(((()())(())()))(())";
	int ans = solution(s);
	printf("%d", ans);
}