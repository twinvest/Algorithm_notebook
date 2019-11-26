#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int solution(string s)
{
	if (s.size() == 1)
		return  1;
	int answer = 10001;
	int index = s.size() / 2;

	for (int x = index; x > 0; x--) //여기까지 나하고 똑같음
	{
		string print = "";
		string compare = "";
		int count = 1;
		for(int i=0; i<s.size(); i+=x) //이 부분도 동일
		{ 
			string cur = s.substr(i, x);

			if (compare.empty()) //최초 초기화
			{
				compare = cur;
				continue;
			}
			
			if (compare != cur)
			{
				if (i + x >= s.size()) //이 조건이 의미하는바
				{
					print += cur;
				}
				if (count > 1)
				{
					print += to_string(count) + compare;
				}
				else
				{
					print += compare;
				}
				compare = cur;
				count = 1;
			}
			else //compare == cur
			{
				count++;
				if (i + x >= s.size()) //이 조건이 의미하는바
				{
					print += to_string(count) + cur; //이 부분 생각못함.
				}
			}
		}
		answer = min(answer, (int)print.size());
	}
	return answer;
}

int main()
{
	string s = "aabbaccc";
	int ans = solution(s);
	printf("%d", ans);
}