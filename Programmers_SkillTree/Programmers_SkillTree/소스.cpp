#include <string>
#include <vector>

using namespace std;
int arr[20][26] = {0, };

int solution(string skill, vector<string> skill_trees) {
	int checknum = 0;
	int answer = 0;
	for (int i = 0; i < skill.length(); i++)
	{
		char check = skill[i];
		for (int j = 0; j < skill_trees.size(); j++)
		{
			for (int k = 0; k < skill_trees[j].length(); ++k)
			{
				if (check == skill_trees[j][k])
				{
					arr[j][k] = i + 1;
				}
			}
		}
	}
	for (int i = 0; i < skill_trees.size(); ++i)
	{
		bool flag = false;
		int num = 1;
		for (int j = 0; j < skill_trees.at(i).size(); ++j)
		{
			if (arr[i][j] == 0) continue;
			else //0이 아닌경우
			{
				if (arr[i][j] - num < 0 || arr[i][j] - num > 0)
				{
					flag = false;
					break;
				}
				else if(num == arr[i][j]){
					num = arr[i][j] + 1;
					flag = true;
					continue;
				}
			}

		}
		if (flag)
			answer++;
	}
	return answer;
}

int main()
{
	string skill = "BCD";
	vector<string> skill_trees;
	skill_trees.push_back("BACDE");
	skill_trees.push_back("CBADF");
	skill_trees.push_back("AECB");
	skill_trees.push_back("BDA");
	
	int ans = solution(skill, skill_trees);
	printf("%d", ans);
}