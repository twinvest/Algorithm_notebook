#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define MAX 9999999999
using namespace std;

bool isPrime(int number)
{
	if (number == 1)
		return false;
	if (number == 2)
		return true;
	if (number % 2 == 0)
		return false;

	bool isPrime = true;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
			return false;
	}

	return isPrime;
}

bool compare(char a, char b)
{
	return a > b;
}

int solution(string numbers) {
	int answer = 0;

	string temp;
	temp = numbers;

	//내림차순 정렬
	sort(temp.begin(), temp.end(), compare);

	//소수인지 판단
	vector<bool> prime(stoi(temp) + 1);
	prime[0] = false;
	for (long long i = 1; i < prime.size(); i++)
	{
		prime[i] = isPrime(i);
	}
	
	string s, sub;
	s = numbers;
	//오름차순 정렬
	sort(s.begin(), s.end());
	
	
	set<int> primes; //set을 쓴 이유는 삽입할때 자동적으로 중복방지
	int l = s.size();
	do {
		for (int i = 1; i <= l; i++)
		{
			//0부터 i번째 전까지 추출
			sub = s.substr(0, i);
			//prime boolean벡터에서 sub이 소수인지 판단
			if (prime[stoi(sub)])
			{
				primes.insert(stoi(sub)); //primes 셋에 삽입.
			}
			cout << s[i-1] << " ";
		}
		cout << endl;
	} while (next_permutation(s.begin(), s.end()));

	//출력
	
	for (auto s : primes)
		cout<< s <<endl;

	answer = primes.size();
	return answer;
}

int main()
{
	string numbers = "310";
	int ans = solution(numbers);
	printf("%d", ans);
}