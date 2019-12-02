#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for(int i=0; i<commands.size(); ++i)
	{ 
		vector<int> tmp = commands[i];
		int start = tmp[0];
		int end = tmp[1];
		int index = tmp[2];
		
		vector<int> arr;
		int count = 0;
		for (int i = start; i <= end; i++)
			arr.push_back(array[i - 1]);

		sort(arr.begin(), arr.end());
		answer.push_back(arr[index-1]);
	}
	return answer;
}

int main()
{
	vector<int> array;
	array.push_back(1);
	array.push_back(5);
	array.push_back(2);
	array.push_back(6);
	array.push_back(3);
	array.push_back(7);
	array.push_back(4);

	vector<vector<int>> command;
	vector<int> command1;
	vector<int> command2;
	vector<int> command3;
	
	command1.push_back(2);
	command1.push_back(5);
	command1.push_back(3);

	command2.push_back(4);
	command2.push_back(4);
	command2.push_back(1);

	command3.push_back(1);
	command3.push_back(7);
	command3.push_back(3);

	command.push_back(command1);
	command.push_back(command2);
	command.push_back(command3);

	vector<int> ans = solution(array, command);
	for (int i = 0; i < ans.size(); ++i)
		printf("%d", ans[i]);
}