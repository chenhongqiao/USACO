#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int b[1005][1005];
int mn[1005];
vector<int> g[1005];
int dfs(int f, int d)
{
    if (b[f][d])
    {
        return b[f][d];
    }
    if (f == 1 && d == 0)
    {
        return 0;
    }
    if (d == 0)
    {
        return -1000000000;
    }
    int tmp = -1000000000;
    for (int i = 0; i < g[f].size(); i++)
    {
        tmp = max(tmp, dfs(g[f][i], d - 1));
    }
    b[f][d] = tmp + mn[f];
    return b[f][d];
}
int main()
{
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> mn[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
    }
    for (int i = 0; i <= 1001; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dfs(j, i);
        }
    }
    int ans = 0;
    for (int i = 0; i <= 1001; i++)
    {
        ans = max(ans, b[1][i] - c * i * i);
    }
    cout << ans << endl;
    return 0;
}