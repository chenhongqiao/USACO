#include <bits/stdc++.h>
#define f first
#define s second
#define umap unordered_map
using namespace std;
char g[305][305];
bool v[305][305];
umap<char, vector<pair<int, int>>> t;
queue<pair<int, int>> q;
queue<int> l;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] >= 'A' && g[i][j] <= 'Z')
            {
                t[g[i][j]].push_back({i, j});
            }
            if (g[i][j] == '@')
            {
                q.push({i, j});
                l.push(0);
                v[i][j] = true;
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> c = q.front();
        for (int i = 0; i < 4; i++)
        {
            int kx = c.f + dx[i];
            int ky = c.s + dy[i];
            if (kx >= 0 && kx < n && ky >= 0 && ky < m && !v[kx][ky] && g[kx][ky] != '#')
            {
                if (g[kx][ky] == '=')
                {
                    cout << l.front() + 1 << endl;
                    return 0;
                }
                if (g[kx][ky] >= 'A' && g[kx][ky] <= 'Z')
                {
                    for (int i = 0; i < 2; i++)
                    {
                        if (kx != t[g[kx][ky]][i].f || ky != t[g[kx][ky]][i].s)
                        {
                            q.push({t[g[kx][ky]][i].f, t[g[kx][ky]][i].s});
                            l.push(l.front() + 1);
                        }
                    }
                }
                if (g[kx][ky] == '.')
                {
                    v[kx][ky] = true;
                    q.push({kx, ky});
                    l.push(l.front() + 1);
                }
            }
        }
        q.pop();
        l.pop();
    }
    return 0;
}