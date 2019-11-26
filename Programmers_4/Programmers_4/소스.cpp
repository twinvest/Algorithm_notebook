#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(string s) {
	int answer = stoi(s);
	return answer;
}

int main()
{
	string s = "-1234";
	int a = solution(s);
	printf("%d", a);
}