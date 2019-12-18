#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<string> paths;
int dfs(string begin, string target, vector<string> words, vector<string> paths, int depth)
{
	int large = 987654321;
	if (depth-1 == words.size())
		return 0;
	if (begin == target)
	{
		for (int i = 0; i < paths.size(); ++i)
		{
			cout << paths[i] << " ";
		}
		printf(" %d", paths.size());
		cout << endl;
		return paths.size();
	}
		
	for (int i = 0; i < words.size(); ++i)
	{
		if (find(paths.begin(), paths.end(), words[i]) != paths.end())
			continue;
		else
		{
			int check = 0;
			string comp = words[i];

			for (int j = 0; j < begin.size(); ++j)
			{
				if (comp[j] == begin[j]) check++;
				if (check == begin.size() - 1)
				{
					begin = words[i];
					paths.push_back(begin);
					
					large = min(dfs(begin, target, words, paths, depth + 1), large);
					paths.erase(paths.begin() + depth);
				}
			}
		}
	}
	return large;
}



int solution(string begin, string target, vector<string> words) {
	//처음시작하면서 target이 words안에있는지 확인하고 없으면 바로 0리턴하고 종료
	bool flag = true;
	for (int i = 0; i < words.size(); i++)
	{
		if (target == words[i])
		{
			flag = false;
			break;
		}
	}
	if (flag) return 0;


	int answer = 0;
	for (int i = 0; i < words.size(); ++i)
	{
		int check = 0;
		string comp = words[i];
		for (int j = 0; j < begin.size(); ++j)
		{
			if (comp[j] == begin[j]) check++;
			if (check == begin.size() - 1)
			{
				begin = words[i];
				paths.push_back(begin);
				answer = dfs(begin, target, words, paths, 1);
			}
		}
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