#include <bits/stdc++.h>
using namespace std;
char g[55][55];
int n, m;
int c[55][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnnt[55][55][4];
void coloring(int x, int y, int mark)
{
    queue<pair<int, int>> q;
    c[x][y] = mark;
    q.push({x, y});
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int kx = q.front().first + dx[i];
            int ky = q.front().second + dy[i];
            if (kx >= 0 && kx < n && ky >= 0 && ky < m && g[kx][ky] == 'X' && !c[kx][ky])
            {
                c[kx][ky] = mark;
                q.push({kx, ky});
            }
        }
        q.pop();
    }
}
struct st
{
    int x, y;
    int dep;
};
void connect(int x, int y)
{
    queue<st> q;
    bool v[55][55] = {false};
    v[x][y] = true;
    q.push({x, y, 1});
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int kx = q.front().x + dx[i];
            int ky = q.front().y + dy[i];
            if (kx >= 0 && kx < n && ky >= 0 && ky < m && !v[kx][ky])
            {
                if (c[kx][ky])
                {
                    if (!cnnt[x][y][c[kx][ky]])
                    {
                        cnnt[x][y][c[kx][ky]] = q.front().dep;
                    }
                }
                else
                {
                    v[kx][ky] = true;
                    q.push({kx, ky, q.front().dep + 1});
                }
            }
        }
        q.pop();
    }
    for (int i = 1; i <= 3; i++)
    {
        if (!cnnt[x][y][i])
        {
            cnnt[x][y][i] = 100000005;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'X' && !c[i][j])
            {
                coloring(i, j, cnt);
                cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '.')
            {
                connect(i, j);
            }
        }
    }
    int ans = 100000000;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'X')
            {
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (g[k][l] == 'X')
                    {
                        continue;
                    }
                    for (int w = 1; w <= 3; w++)
                    {
                        int a, b;
                        switch (w)
                        {
                        case 1:
                            a = 2;
                            b = 3;
                            break;
                        case 2:
                            a = 1;
                            b = 3;
                            break;
                        case 3:
                            a = 1;
                            b = 2;
                            break;
                        }
                        int tmp = cnnt[i][j][w] + cnnt[i][j][a] + cnnt[k][l][w] + cnnt[k][l][b] - 2;
                        tmp = min(tmp, cnnt[i][j][w] + cnnt[i][j][b] + cnnt[k][l][w] + cnnt[k][l][a] - 2);
                        tmp = min(tmp, cnnt[i][j][w] + cnnt[k][l][a] + cnnt[k][l][b] + abs(i - k) + abs(j - l) - 2);
                        ans = min(ans, tmp);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}