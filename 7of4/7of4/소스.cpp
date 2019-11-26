#include<iostream>
#include<cstdio>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
void printPicked(vector<int>& picked) {
	for (int i = 0; i < picked.size(); i+=2) {
		printf("{%d, %d}\n", picked[i], picked[i + 1]);
	}
}
void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) { printPicked(picked); return; }
	
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}
int main() {
	int n, toPick;
	vector<int> picked;
	scanf("%d %d", &n, &toPick);
	pick(n, picked, toPick);
}