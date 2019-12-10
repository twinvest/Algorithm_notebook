#include <string>
#include <vector>

using namespace std;
int ans = 0;
void dfs(vector<int> numbers, int target, int sum, int idx) 
{
	if (idx == numbers.size()) 
	{
		if (sum == target) ans++;
		return;
	}

	dfs(numbers, target, sum + numbers[idx], idx + 1);
	dfs(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) 
{
	dfs(numbers, target, 0, 0);
	return ans;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	int target = 3;
	
	int ans = solution(v, target);
	printf("%d", ans);
}