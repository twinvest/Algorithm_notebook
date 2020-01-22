#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable : 4996)
std::vector<int> v;
int main()
{
	int N, tmp;
	std::cin >> N;
	for (int i = 0; i < N; ++i){
		std::cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	printf("%d\n", v[v.size()/2]);
}