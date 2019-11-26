#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)
using namespace std;
struct offsets
{
	int x, y;
};
offsets moveDir[8] = { { -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 } };
char word[11]; //전역변수로 뺐다
char board[5][5]; //5*5 Boggle
bool record[5][5][10]; //기록용(예시에 나와있는 단어의 길이가 10을 초과하지 않기 때문에 길이를 임의로 10이라고 정의)
bool search(int y, int x, int idx)
{
	record[y][x][idx] = 1; //방문했다는 것을 기록
	//첫 글자와 동일하지 않으면 해당 문장이 아니다
	if (board[y][x] != word[idx])
		return false;
	//마지막 글자까지 동일하다면 참
	if (idx == strlen(word) - 1)
		return true;
	for (int i = 0; i < 8; i++)
	{
		if (y + moveDir[i].y < 5 && x + moveDir[i].x < 5 && y + moveDir[i].y >= 0 && x + moveDir[i].x >= 0)
		{
			if (record[y + moveDir[i].y][x + moveDir[i].x][idx + 1])
				continue;//이미 방문했다면 또 다시 방문할 필요 없음
			if (search(y + moveDir[i].y, x + moveDir[i].x, idx + 1))
				return true;//재귀 호출
		}
	}
	return false;
}
void answer(void)
{
	int  word_num;
	for (int i = 0; i < 5; i++)
		scanf("%s", board[i]);
	scanf("%d", &word_num);
	for (int j = 0; j < word_num; j++)
	{
		memset(record, 0, sizeof(record));
		scanf("%s", word);
		printf("%s ", word);
		bool result = false;
		for (int k = 0; k < 5; k++)
		{
			for (int l = 0; l < 5; l++)
			{
				if (search(k, l, 0)) result = true;
				if (result) break; //찾았다면 반복문 탈출
			}
			if (result) break;
		}

		if (result)	puts("YES");
		else puts("NO");
	}
}

int main(void)
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
		answer();
	return 0;
}