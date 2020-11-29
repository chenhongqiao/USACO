#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
bool v[1005][1005];
int g[1005][1005];
int r, c;
int dx[3] = {0, 1, -1};
int dy[3] = {0, 1, -1};
void floodfill(int x, int y)
{
	queue<pair<int, int>> q;
	v[x][y] = true;
	q.push({x, y});
	while (!q.empty())
	{
		int kx = q.front().f;
		int ky = q.front().s;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				int nx = kx + dx[i];
				int ny = ky + dy[j];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c &&
					g[nx][ny] != 0 && !v[nx][ny])
				{
					v[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
		q.pop();
	}
}
int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> g[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (g[i][j] != 0 && !v[i][j])
			{
				ans++;
				floodfill(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
