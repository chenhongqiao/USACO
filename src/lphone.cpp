#include <bits/stdc++.h>
using namespace std;
int w, h;
char g[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int b[105][105][4];
bool v[105][105];
pair<int, int> s;
struct r
{
    int a, b, c;
};
int ans = 100000000;
void dfs(int x, int y, int l, int dep, int c)
{
    if (x < 0 || x >= w || y < 0 || y >= h || g[x][y] == '*')
    {
        return;
    }
    if (g[x][y] == 'C' && (x != s.first || y != s.second))
    {
        ans = min(ans, c);
        return;
    }
    if (c >= b[x][y][l])
    {
        return;
    }
    else if (c < b[x][y][l])
    {
        b[x][y][l] = c;
    }
    if (!v[x + dx[l]][y + dy[l]])
    {
        v[x + dx[l]][y + dy[l]] = true;
        dfs(x + dx[l], y + dy[l], l, dep + 1, c);
        v[x + dx[l]][y + dy[l]] = false;
    }
    for (int i = 0; i < 4; i++)
    {
        if (i == l)
        {
            continue;
        }
        else if (!v[x + dx[i]][y + dy[i]])
        {
            v[x + dx[i]][y + dy[i]] = true;
            dfs(x + dx[i], y + dy[i], i, dep + 1, c + 1);
            v[x + dx[i]][y + dy[i]] = false;
        }
    }
}
int main()
{
    for (int i = 0; i < 105; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                b[i][j][k] = 100000000;
            }
        }
    }

    cin >> h >> w;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'C')
            {
                s.first = i;
                s.second = j;
            }
        }
    }
    v[s.first][s.second] = true;
    for (int i = 0; i < 4; i++)
    {
        dfs(s.first, s.second, i, 0, 0);
    }
    cout << ans << endl;
    return 0;
}