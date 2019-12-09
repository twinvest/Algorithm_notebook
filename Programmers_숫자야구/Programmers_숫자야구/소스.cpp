#include <string>
#include <vector>

using namespace std;
vector<vector<int>> v;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	// 가장 작은 숫자 : 123 / 가장 큰 숫자 : 987 까지 비교하면서 스트라이크 볼이 맞는 수를 찾아간다. 
	//수 비교는 string으로 바꿔서 해도 될듯 (안 그러면 10 나누고 mod 연산 해야하니까 )

	for (int i = 123; i <= 987; i++) {
		string tmp = to_string(i);
		bool flag = true;

		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) continue;// 숫자 중복 비허용 
		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') continue; //숫자 0 비허용 

		for (int j = 0; j < baseball.size(); j++) {
			int strike = 0, ball = 0;
			for (int a = 0; a < 3; a++) {
				for (int b = 0; b < 3; b++) {
					string num = to_string(baseball[j][0]); //매번 새로 가져옴 
					if (a == b && tmp[a] == num[b]) {
						//스트라잌
						strike++;
						continue;
					}
					else if (tmp[a] == num[b]) {
						ball++;
						continue;
					}
				}
			}//for a

			//한 숫자를 다 살펴봄 
			if (strike != baseball[j][1] || ball != baseball[j][2]) {
				//i는 알맞은 숫자가 아님 
				flag = false;
				break;
			}
		}//for j(baseball)
		if (flag) answer++;
	}
	return answer;
}
int main()
{
	vector<int> v1;
	v1.push_back(123);
	v1.push_back(1);
	v1.push_back(1);

	vector<int> v2;
	v2.push_back(356);
	v2.push_back(1);
	v2.push_back(0);

	vector<int> v3;
	v3.push_back(489);
	v3.push_back(0);
	v3.push_back(1);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	int ans = solution(v);
	printf("%d", ans);
}