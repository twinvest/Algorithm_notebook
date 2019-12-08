#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	for (int i = 0; i < citations.size(); ++i)
	{
		int hindex = i;
		int count = 0;
		int count2 = 0;
		
		for (int j = 0; j < citations.size(); ++j)
			if (hindex <= citations[j])
				count++;

		for (int j = citations.size()-1; j >= 0; j--)
			if (hindex >= citations[j])
				count2++;
	
		if (i >= count)
		{
			if (count2 <= i)
			{
				answer = i;
				break;
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < citations.size(); ++i)
	{
		if (citations.size() < citations[i])
			flag = true;
		else
		{
			flag = false;
			break;
		}
			
	}
	if (flag) return citations.size();	
	return answer;
}


int main()
{
	vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);

	int ans = solution(v);
	printf("%d", ans);
}