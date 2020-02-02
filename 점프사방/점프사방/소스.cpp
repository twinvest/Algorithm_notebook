#include<iostream>
#include<vector>
#include<string>
#pragma warning (disable : 4996)
using namespace std;
int Y, X;
int dir[5][2] = {
	{0,0},
	{0,1},  //¿À
	{1,0},  //¾Æ·¡	
	{0,-1}, //¿Þ
	{-1,0}  //À§
};

bool inside(int y, int x)
{
	return (y >= 0 && y < Y) && (x >= 0 && x < X);
}

int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		vector<pair<pair<int, int>, int>> v;
		int arr[20][20];
		int participation, fall;

		cin >> Y >> X >> participation;

		for (int i = 0; i < Y; ++i)
			for (int j = 0; j < X; ++j)
				scanf("%d", &arr[i][j]);

		for (int i = 0; i < participation; ++i)
		{
			int y, x, jump;
			cin >> y >> x >> jump;
			--y; --x;
			v.push_back(make_pair(make_pair(y, x), jump));
		}

		cin >> fall;
		for (int i = 0; i < fall; ++i)
		{
			int y, x;
			cin >> y >> x;
			--y; --x;
			arr[y][x] = -1;
		}
		int sum = 0;

		for (int i = 0; i < v.size(); ++i)
		{
			for (int j = 0; j < v[i].second; ++j)
			{
				string tmp = to_string(arr[v[i].first.first][v[i].first.second]);
				int jump = tmp[1] - 48;
				int direction = tmp[0] - 48;

				int ny = v[i].first.first + dir[direction][0] * jump;
				int nx = v[i].first.second + dir[direction][1] * jump;
				
				if (!inside(ny, nx))
				{
					v[i].first.first = -1;
					v[i].first.second = -1;
					break;
				}
				v[i].first.first = ny;
				v[i].first.second = nx;
			}

			if (arr[v[i].first.first][v[i].first.second] == -1)
			{
				v[i].first.first = -1;
				v[i].first.second = -1;
			}
		}

		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].first.first == -1 && v[i].first.first == -1)
				continue;
			sum += (arr[v[i].first.first][v[i].first.second] * 100);
		}

		printf("%d\n", sum - (participation * 1000));
	}
}