#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;
char arr[11];
bool desc(int a, int b) { return a > b; }
long long solution(long long n) {
	long long answer;
	string change = to_string(n); //롱롱을 스트링으로
	vector<char> v1; //char로 하나씩 삽입해서 정렬시킬 벡터

	for (int i = 0; i < change.length(); ++i)
	{
		v1.push_back(change[i]); //벡터에 char 하나씩 삽입
	}
	sort(v1.begin(), v1.end(), desc); //벡터 정렬
	//벡터를 다시 스트링으로
	for (int i = 0; i < v1.size(); i++)
	{
		arr[i] = v1.at(i);
	}
	//스트링을 다시 롱롱으로
	answer = atoll(arr);
	return answer;
}

int main()
{
	long long num = 118372;
	long long ans = solution(num);
	cout << ans;
}