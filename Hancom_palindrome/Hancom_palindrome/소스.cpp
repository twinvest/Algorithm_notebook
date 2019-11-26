#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int flag = 0;

bool is_palindrome(string s) {

	if (s.size() == 1) return false;
	string s_reverse = s;
	reverse(s_reverse.begin(), s_reverse.end());
	return s == s_reverse ? true : false;

}

void dq(string s)
{
	//더 이상 나눌 수 없는 기저사례
	if (s.size() == 1) return; 
	
	int mid = s.size() / 2;
	int check = s.size() % 2;

	//가운데 패린드롬 확인
	int i = 1;
	while (1)
	{
		if (!check)//문자열 길이가 짝수
		{
			if (is_palindrome(s.substr(mid - i, 2 * i)))
			{
				++flag;
			}
			++i;
		}
		else//문자열 길이가 홀수
		{
			if (is_palindrome(s.substr(mid - i, 2*i+1)))
			{
				++flag;
			}
			++i;
		}
		if (mid - i + 1 == 0) break;
	}

	if (!check)
	{
		dq(s.substr(0, mid));//왼쪽 패린드롬 확인
		dq(s.substr(mid, mid));//오른쪽 패린드롬 확인
	}
	else
	{
		dq(s.substr(0, mid+1));//왼쪽 패린드롬 확인
		dq(s.substr(mid, mid+1));//오른쪽 패린드롬 확인
	}
	

}


int main() {

	string s = "abaabax";
	dq(s);

	printf("%d", flag);
	return 0;

}