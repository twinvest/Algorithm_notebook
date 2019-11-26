#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Boggle
{
public:
	// 게임판 정보
	vector<string> board;

	Boggle()
	{
		// 게임판 세팅
		board.push_back("URLPM");
		board.push_back("XPRET");
		board.push_back("GIAET");
		board.push_back("XTNZY");
		board.push_back("HOQRS");
	}

	// 5x5 게임판에서 주어진 단어가 시작하는지 반환.
	bool hasWord(int x, int y, const string& word)
	{
		// 범위를 넘어가면 실패.
		if (x < 0 || y < 0 || x >= 5 || y >= 5) return false;
		// 단어의 첫번째가 안맞으면 실패;
		if (board[x][y] != word[0]) return false;
		// 단어의 첫번째가 맞았는데 길이가 1이면 성공.
		if (word.size() == 1) return true;
		// 현재 위치 중심으로 주변을 검색한다.
		for (int dx = -1; dx <= 1; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				if (hasWord(x + dx, y + dy, word.substr(1)))
					return true;
			}
		}
		return false;
	}
};

int main()
{
	Boggle boggle;

	string target = "";
	cout << "찾을 문자열 입력" << endl;
	cin >> target;
	bool bFound = false;

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			if (boggle.hasWord(x, y, target))
			{
				bFound = true;
				break;
			}
		}
		if (bFound) break;
	}
	cout << "찾을 문자열 " << target << " 존재 : " << (bFound ? "YES" : "NO") << endl;
	system("pause");
}