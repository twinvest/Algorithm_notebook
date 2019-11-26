#include <string>
#include <vector>
#include <map>

using namespace std;
vector<vector<string>> clothes;
vector<string> c1;
vector<string> c2;
vector<string> c3;

int solution(vector<vector<string>> clothes) {
	map<string, int> m;
	int answer = 1;
	for (int i = 0; i < clothes.size(); ++i)
	{
		vector<string> tmp = clothes.at(i);
		m[tmp[1]]++;
	}
	for (auto s : m)
		answer *= ++s.second;
	return answer - 1;
}

int main()
{
	c1.push_back("yellow_hat");
	c1.push_back("face");
	clothes.push_back(c1);
	
	c2.push_back("blue_sunglasses");
	c2.push_back("face");
	clothes.push_back(c2);
	
	c3.push_back("green_turban");
	c3.push_back("face");
	clothes.push_back(c3);

	int ans = solution(clothes);
	printf("%d", ans);
}