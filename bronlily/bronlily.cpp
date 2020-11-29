#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
short int g[35][35];
bool v[35][35];
queue<pair<int, int>> q;
queue<int> l;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main()
{
    int m, n, m1, m2;
    cin >> m >> n >> m1 >> m2;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 3)
            {
                q.push({i, j});
                l.push(0);
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> c = q.front();
        for (int i = 0; i < 4; i++)
        {
            int o = (((i + 2) % 4) / 2) * 2;
            for (int j = 0; j < 2; j++)
            {
                int kx = c.f + dx[i] * m1 + dx[o + j] * m2;
                int ky = c.s + dy[i] * m1 + dy[o + j] * m2;
                if (kx >= 0 && kx < m && ky >= 0 && ky < n && !v[kx][ky] && (g[kx][ky] == 1 || g[kx][ky] == 4))
                {
                    if (g[kx][ky] == 4)
                    {
                        cout << l.front() + 1 << endl;
                        return 0;
                    }
                    else
                    {
                        v[kx][ky] = true;
                        q.push({kx, ky});
                        l.push(l.front() + 1);
                    }
                }
                kx = c.f + dx[i] * m2 + dx[o + j] * m1;
                ky = c.s + dy[i] * m2 + dy[o + j] * m1;
                if (kx >= 0 && kx < m && ky >= 0 && ky < n && !v[kx][ky] && (g[kx][ky] == 1 || g[kx][ky] == 4))
                {
                    if (g[kx][ky] == 4)
                    {
                        cout << l.front() + 1 << endl;
                        return 0;
                    }
                    else
                    {
                        v[kx][ky] = true;
                        q.push({kx, ky});
                        l.push(l.front() + 1);
                    }
                }
            }
        }
        q.pop();
        l.pop();
    }
    return 0;
}