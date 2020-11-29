#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int dep[500005];
int lg2[500006];
int info[500005][22];
vector<int> r[500005];
struct farm
{
    int fa;
    vector<int> s;
} f[500005];
void broot(int cur, int fa)
{
    for (int i = 0; i < r[cur].size(); i++)
    {
        if (r[cur][i] != fa)
        {
            f[cur].s.push_back(r[cur][i]);
            f[r[cur][i]].fa = cur;
            broot(r[cur][i], cur);
        }
    }
}
void dfs(int cur, int fa)
{
    dep[cur] = dep[fa] + 1;
    info[cur][0] = fa;
    for (int i = 0; i < f[cur].s.size(); i++)
    {
        dfs(f[cur].s.at(i), cur);
    }
}
int lca(int u, int v)
{
    if (dep[u] < dep[v])
    {
        swap(u, v);
    }
    for (int i = 20; i >= 0; i--)
    {
        if (dep[u] > dep[v])
        {
            u = info[u][i];
        }
    }
    if (u == v)
    {
        return v;
    }
    for (int i = lg2[dep[u]]; i >= 0; i--)
    {
        if (info[u][i] != info[v][i])
        {
            u = info[u][i];
            v = info[v][i];
        }
    }
    return info[u][0];
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        r[u].push_back(v);
        r[v].push_back(u);
    }
    broot(s, 0);
    dfs(s, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= lg2[dep[i]]; j++)
        {
            info[i][j] = info[info[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}