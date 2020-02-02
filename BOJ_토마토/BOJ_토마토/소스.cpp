#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
queue< pair<pair<int, int>, int> > q;
int day = 1;
int check = 0;
int X, Y, Z;
int arr[100][100][100];
int dir[6][3] = { {0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,1},{0,0,-1} };

bool inside(int y1, int x1, int z1)
{
	return (y1 < Y && y1 >= 0) && (x1 < X && x1 >= 0) && (z1 < Z && z1 >= 0);
}

void bfs(int arr[100][100][100], int day)
{
	int size = q.size();
	for (int i = 0; i < size; i++)
	{
		int y1, x1, z1;
		y1 = q.front().first.first;
		x1 = q.front().first.second;
		z1 = q.front().second;
		q.pop();

		for (int d = 0; d < 6; ++d)
		{
			int ny, nx, nz;
			nz = z1 + dir[d][2];
			ny = y1 + dir[d][0];
			nx = x1 + dir[d][1];

			//범위안이면서 방문할곳이 0이면
			if (inside(ny, nx, nz) && arr[nz][ny][nx] == 0)
			{
				arr[nz][ny][nx] = day + 1;//방문
				q.push(make_pair(make_pair(ny, nx), nz));
				check++;
			}
		}
	}
}
int main(void)
{
	scanf("%d", &X);
	scanf("%d", &Y);
	scanf("%d", &Z);
	for (int k = Z - 1; k >= 0; --k)
	{
		for (int i = 0; i < Y; i++) //입력
		{
			for (int j = 0; j < X; j++)
			{
				scanf("%d", &arr[k][i][j]);
				if (arr[k][i][j] == 1)
				{
					q.push(make_pair(make_pair(i, j), k));
				}
			}
		}
	}

	do
	{
		check = 0;
		bfs(arr, day);
		day++;
	} while (check);

	for (int z = 0; z < Z; z++)
		for (int y = 0; y < Y; y++)
			for (int x = 0; x < X; x++)
				if (arr[z][y][x] == 0)
					day = 1;
	printf("%d\n", day - 2);
}