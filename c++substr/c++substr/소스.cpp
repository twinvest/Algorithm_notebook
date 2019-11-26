#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
void letgo(string s1) {
	for (int i = 0; i < s1.size(); i++)
		printf("%c", s1[i]);
}

int main() {
	string s = "taewoo";
	letgo(s.substr(1));
}