#include <string>
#include <vector>
#include<iostream>
#include <cstdio>
using namespace std;
int arr[501] = { 0, }; //길이를 저장할 배열
int checkchar(string s)
{
	vector<char> v1;
	for (int i = 0; i < s.length(); ++i)
	{
		if (find(v1.begin(), v1.end(), s.at(i)) != v1.end()) continue;
		else v1.push_back(s.at(i));
	}
	return v1.size();
}

int solution(string s) {
	int answer = 0;

	int check = 0; //체크할 문자의 길이
	for (int i = 0; i < (s.length() / 2); ++i) //문자열 절반 길이 반복
	{
		int count = 0;
		check++; // 1씩검색, 2씩검색, 3씩검색, 4씩검색
		for (int i = 1; i < s.length(); i += check)
		{
			int num = check;
			if (i - 1 + num > s.length() || i - 1 > s.length()) break;
			string check_str = s.substr(i - 1, num);
			string original = s.substr(i - 1 + num, num);
			if (check_str == original)
				count++;
			
		}

		arr[i] = s.length() - (count * check);
		if (count != 0)
			arr[i] += count;
		if (count != 0 && check == 1)
		{
			arr[i] = s.length() - (count * check);
			arr[i] += checkchar(s);
		}

	}
	

	//가장 낮은 값을 반환할 for문
	answer = arr[0];
	for (int i = 0; i < (s.length() / 2) - 1; ++i)
		if (answer > arr[i + 1])
			answer = arr[i + 1];
	return answer;
}


int main()
{
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbb";
	int ans = solution(s);
	printf("%d", ans);
}