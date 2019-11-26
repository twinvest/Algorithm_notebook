#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll num = 600851475143;
	ll p = 2;
	ll ans = 0;
	while (num >= p * p) {
		if (num % p == 0) {
			ans = p;
			cout << p << endl;
			while (num % p == 0) {
				num /= p;
			}
		}
		else p++;
	}
	cout << "마지막 : " << num << endl;
	if (num != 1) cout << num;
	else cout << ans;
}