#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 101;
bool visited[51];
//예전 commit코드와 비교해볼걸

void dfs(int cnt, string begin, string target, int idx, vector<string>& words) {
	if (begin == target) 
	{
		if (answer > cnt) answer = cnt;
		return;
	}

	for (int i = 0; i < words.size(); i++) 
	{
		int tmp_cnt = 0;
		if (!visited[i]) 
		{
			string tmp = words.at(i);
			for (int j = 0; begin[j]; j++) 
			{
				if (begin[j] != tmp[j]) 
				{
					tmp_cnt++;
				}
			}
			//for j
			if (tmp_cnt == 1) 
			{
				visited[i] = true;
				dfs(cnt + 1, tmp, target, i + 1, words);
				visited[i] = false;
			}
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	bool flag = false;
	for (int i = 0; i < words.size(); i++) 
	{
		if (words.at(i) == target) 
		{
			flag = true;
			break;
		}
	}
	if (!flag) answer = 0;
	else {
		//탐색 시작 
		dfs(0, begin, target, 0, words);
	}
	return answer;
}

int main()
{
	string begin = "hit";
	string target = "cog";
	vector<string> v;
	
	v.push_back("hot");
	v.push_back("dot");
	v.push_back("dog");
	v.push_back("lot");
	v.push_back("log");
	v.push_back("cog");

	int ans = solution(begin, target, v);
	printf("%d", ans);
}