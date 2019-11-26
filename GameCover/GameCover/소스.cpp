#include <iostream>
using namespace std;
//주어진 칸을 덮을 수 있는 네가지 방법
//블록을 구성하는 세 칸의 상대적 위치 (dy, dx)의 목록
const int coverType[4][3][2] = {
	//ㅁㅁ
	//ㅁ
	{{0,0}, {1, 0}, {0, 1}},
	//ㅁㅁ
	//  ㅁ
	{{0, 0}, {0, 1}, {1, 1}},
	//ㅁ
	//ㅁㅁ
	{{0, 0}, {1, 0}, {1, 1}},
	//  ㅁ
	//ㅁㅁ
	{{0, 0}, {1, 0}, {1, -1}}
};

//board의 (y, x)를 type번 방법으로 덮거나, 덮었던 블록을 없앤다
//push가 1이면 덮고, -1이면 덮었던 블록을 없앤다
//만약 블록이 제대로 덮이지 않은 경우(게임판 밖으로 나가거나
//겹치거나 검은 칸을 덮을 때) false 반환
bool set(int board[][20], int y, int x, int H, int W, int type, int push)
{
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) //범위를 초과할 경우
			ok = false;
		else if ((board[ny][nx] += push) > 1) //겹쳐질 경우
			ok = false;
	}
	return ok;
}

//board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환
//board[i][j]=1 이미 덮인 칸 혹은 검은 칸
//board[i][j]=0 아직 덮이지 않은 칸
int cover(int board[][20], int H, int W)
{
	//아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다
	int y = -1, x = -1;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			if (!board[i][j]) //아직 채우진 못한 칸 찾음
			{
				y = i;
				x = j;
				break;
			}
		if (y != -1)
			break;
	}
	//기저 사례: 모든 칸을 채웠으면 1을 반환
	if (y == -1)
		return 1;
	int result = 0;
	for (int type = 0; type < 4; type++)
	{
		//만약 board[y][x]를 type 형태로 덮을 수 있으면 재귀 호출
		if (set(board, y, x, H, W, type, 1))
			result += cover(board, H, W);
		//덮었던 블록 치운다
		set(board, y, x, H, W, type, -1);
	}
	return result;
}

int main(void)
{
	int test_case, H, W; //H=height, W=width
	int board[20][20];
	char bw[20]; //black/white

	cin >> test_case;
	if (test_case < 0 || test_case > 30)
		exit(-1);
	for (int i = 0; i < test_case; i++)
	{
		cin >> H >> W;
		if (H < 1 || H>20 || W < 1 || W>20)
			exit(-1);
		for (int i = 0; i < H; i++)
		{
			cin >> bw;
			for (int j = 0; j < W; j++)
				board[i][j] = (bw[j] == '#') ? 1 : 0;
		}
		cout << cover(board, H, W) << endl;
	}
	return 0;
}