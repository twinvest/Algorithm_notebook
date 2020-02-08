#include<cstdio>
#include<vector>
#include<algorithm>
#pragma warning (disable : 4996)
using namespace std;
int arr[1000];
vector<pair<int, int>> v;
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int main()
{
	int size, time;
	scanf("%d", &size);
	for (int i = 0; i < size; ++i){
		scanf("%d", &time);
		v.push_back(make_pair(i, time));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < size; ++i)  arr[i] = v[i].second;
	int sum = 0;
	for (int i = 1; i <= size; ++i)
		for (int j = 0; j < i; ++j)
			sum += arr[j];
	printf("%d", sum);
}