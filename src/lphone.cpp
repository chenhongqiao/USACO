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
vector<r> ans;
int dfs(int x, int y, int l, int dep)
{
    if (x < 0 || x >= w || y < 0 || y >= h || g[x][y] == '*')
    {
        return 10000000;
    }
    if (g[x][y] == 'C' && (x != s.first || y != s.second))
    {
        return 0;
    }
    if (b[x][y][l] != -1)
    {
        return b[x][y][l];
    }
    int tmp = 10000000;
    if (!v[x + dx[l]][y + dy[l]])
    {
        v[x + dx[l]][y + dy[l]] = true;
        tmp = min(tmp, dfs(x + dx[l], y + dy[l], l, dep + 1));
        v[x + dx[l]][y + dy[l]] = false;
    }
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        if (i == l)
        {
            continue;
        }
        else if (!v[x + dx[i]][y + dy[i]])
        {
            cnt++;
            v[x + dx[i]][y + dy[i]] = true;
            ans.push_back({x, y, i});
            tmp = min(tmp, dfs(x + dx[i], y + dy[i], i, dep + 1) + 1);
            v[x + dx[i]][y + dy[i]] = false;
            ans.pop_back();
        }
    }

    b[x][y][l] = tmp;
    return tmp;
}
int main()
{
    for (int i = 0; i < 105; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                b[i][j][k] = -1;
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
    int ans = 10000000;
    v[s.first][s.second] = true;
    for (int i = 0; i < 4; i++)
    {
        int tmp = dfs(s.first, s.second, i, 0);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}