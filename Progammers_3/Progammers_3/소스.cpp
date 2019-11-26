#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class a
{
	public:
	int gcd(int a, int b)
	{
		int c;
		while (b != 0)
		{
			c = a % b;
			a = b;
			b = c;
		}
		return a;
	}

	int lcm(int a, int b)
	{
		return a * b / gcd(a, b);
	}
};


vector<int> solution(int n, int m) {
	vector<int> answer;
	a a;
	int gcd = a.gcd(n, m);
	int lcm = a.lcm(n, m);
	answer.push_back(gcd);
	answer.push_back(lcm);
	return answer;
}
int main()
{
	int n, m;
	n = 3;
	m = 12;
	vector<int> a = solution(n, m);
}