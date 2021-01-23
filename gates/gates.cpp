#include <bits/stdc++.h>
using namespace std;
bool g[4005][4005];
int n;
bool v[4005][4005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void floodfill(int x, int y)
{
    v[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int kx = q.front().first + dx[i];
            int ky = q.front().second + dy[i];
            if (kx >= 0 && kx <= 4000 && ky >= 0 && ky <= 4000 && !v[kx][ky] && !g[kx][ky])
            {
                v[kx][ky] = true;
                q.push({kx, ky});
            }
        }
        q.pop();
    }
}
int main()
{
    //freopen("gates.in", "r", stdin);
    //freopen("gates.out", "w", stdout);
    cin >> n;
    int x = 2000, y = 2000;
    g[x][y] = true;
    for (int i = 0; i < n; i++)
    {
        char d;
        cin >> d;
        if (d == 'N')
        {
            x++;
            g[x][y] = true;
            x++;
            g[x][y] = true;
        }
        else if (d == 'S')
        {
            x--;
            g[x][y] = true;
            x--;
            g[x][y] = true;
        }
        else if (d == 'E')
        {
            y++;
            g[x][y] = true;
            y++;
            g[x][y] = true;
        }
        else if (d == 'W')
        {
            y--;
            g[x][y] = true;
            y--;
            g[x][y] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 4000; i++)
    {
        for (int j = 0; j <= 4000; j++)
        {
            if (!g[i][j] && !v[i][j])
            {
                ans++;
                floodfill(i, j);
            }
        }
    }
    cout << ans - 1 << endl;

    return 0;
}