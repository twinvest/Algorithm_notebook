#include<iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#pragma warning(disable : 4996)
using namespace std;
int N; //재료의 개수
int Case; // 1또는 2의 입력방식을 받을 변수 Case
vector< pair<long long, string> > p; //pair를 이용해 순열을 모두 저장


int main()
{
	scanf("%d", &N);    //재료의 수
	scanf("%d", &Case); // 1 or 2
	vector<int> v(N); //자료의 개수만큼 벡터사이즈 정함

	//벡터에다가 숫자들 초기화
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = i + 1;
	}

	//순열과 그 번호를 순서쌍으로 만들고 벡터에다가 저장
	long long count = 0;
	do {
		string tmp = "";
		for (int i = 0; i < v.size(); ++i)
		{
			tmp += to_string(v[i]);
		}
		p.push_back(make_pair(++count, tmp));
	} while (next_permutation(v.begin(), v.end()));

	
	if (Case == 1)
	{
		//순열의 몇번째인지 k를 입력값으로 받는다.
		long long k;
		scanf("%u", &k);


		//일치하는 번호찾아서 second출력
		for (long long i = 0; i < p.size(); ++i)
		{
			if (p[i].first == k)
			{
				//단, 일치하는 번호를 찾으면 스페이스를 추가
				for (long long j = 0; j < p[i].second.size(); ++j)
				{
					cout << p[i].second[j] <<" ";
				}
				
			}
		}
	}
	else
	{
		vector<int> test2(N); //2번째 방법에서 숫자들 입력(사실은 순열)받을 배열
		
		//Case가 2일때 숫자들 입력받을 벡터
		for (int i = 0; i < N; ++i)
		{
			cin >> test2[i];
		}

		//string으로 변환
		string tmp = "";
		for (int i = 0; i < v.size(); ++i)
		{
			tmp += to_string(test2[i]);
		}
		//일치하는 순열찾아서 first출력
		for (long long i = 0; i < p.size(); ++i)
		{
			if (tmp == p[i].second)
				cout << p[i].first;
		}
	}
}