#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const string& a, const string& b) 
{
	return a + b > b + a ? true : false;
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> strArr;
	
	for (int i = 0; i < numbers.size(); i++) 
	{
		strArr.push_back(to_string(numbers.at(i)));
	}
	
	sort(strArr.begin(), strArr.end(), cmp);
	
	for (string str : strArr) 
	{
		answer += str;
	}
	
	if (answer[0] == '0')
		return "0";
	return answer;
}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(51);
	v.push_back(33);
	string ans = solution(v);
	cout << ans << endl;
}