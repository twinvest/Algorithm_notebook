#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<pair<int, int>> v;
	int sum = brown + red;
	int div = 1;
	while (1)
	{
		int mok = sum / div;
		int mod = sum % div;
		if (mod == 0)
			v.push_back(make_pair(div, mok));

		div++;
		if (div == sum+1) break;
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v.at(i).first << " " << v.at(i).second << endl;
	}
	vector<int> answer;
	return answer;
}

int main()
{
	int brown = 24;
	int red = 24;
	vector<int> ans = solution(brown, red);
}