#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;
class tw {
public:
	string a;
	char b;
	tw(string a, char b) : a(a), b(b) {};
};

vector<tw> arr;

bool compare(tw a, tw b)
{
	return a.b > b.b;
}

vector<string> solution(vector<string> strings, int n) {
	
	vector<string> answer;
	sort(strings.begin(), strings.end());
	for (int i = 0; i < strings.size(); ++i)
		arr.push_back(tw(strings[i], strings[i][n]));
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < arr.size(); ++i)
		answer.push_back(arr.at(i).a);
	return answer;
}

int main() 
{
	vector<string> v1;
	vector<string> v2;
	v1.push_back("abce");
	v1.push_back("abcd");
	v1.push_back("cdx");

	v2 = solution(v1, 2);
	for (int i = 0; i < v2.size(); i++)
	{
		cout<< v2.at(i)<<'\n';
	}
}