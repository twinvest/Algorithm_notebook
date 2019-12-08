#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> citations) {
	int index = 0;
	//내림차순 정렬 7 6 4 1 1 0으로 정렬됨.
	sort(citations.begin(), citations.end(), greater<int>());
	
	//비교를 하다가 인덱스에 해당하는 배열 값이 인덱스보다 작거나 같으면 해당 인덱스가 정답
	while (index < citations.size())
	{
		if (citations[index] <= index)
			break;
		index++;
	}
	return index;
}


int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(7);
	v.push_back(0);
	v.push_back(1);
	v.push_back(6);
	v.push_back(4);

	int ans = solution(v);
	printf("%d", ans);
}