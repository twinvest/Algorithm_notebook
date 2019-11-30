#include<cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int solution(int a, int b)
{
	 vector<char> v;
	 string s = to_string(pow(a, b));
	 int index = 0;
	 int count = 0;
	 string copy = "";
	 //cout << s <<endl;
	 for (int i = 0; i < s.size(); ++i)
	 {
		 if (s[i] == '.')
		 {
			 index = i;
			 break;
		 }
	 }
	 for (int i = index; ; i--)
	 { 
		 v.push_back(s[i-1]);
		 ++count;
		 if (count == 5) break;
	 }

	 reverse(v.begin(), v.end());
	 
	 for (int i = 0; i < v.size(); i++)
	 {
		copy = copy + v[i];
	 }
	 int answer = stoi(copy);
	 return answer;

}

int main()
{
	int a = 231;
	int b = 1012;
	int cnt = solution(a, b);
	printf("%d\n", cnt);
}