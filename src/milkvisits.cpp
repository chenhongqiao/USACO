#include <bits/stdc++.h>
using namespace std;
int n, m;
int dep[100005];
int info[100005][20];
int gsum[100005];
int hsum[100005];
int lg2[100005];
vector<int> r[100005];
struct farm
{
    char ct;
    int fa = 0;
    vector<int> s;
} f[100005];
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
    while (dep[u] > dep[v])
    {
        u = info[u][lg2[dep[u] - dep[v]]];
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
void presum(int cur, int fa)
{
    hsum[cur] = hsum[fa];
    gsum[cur] = gsum[fa];
    if (f[cur].ct == 'G')
    {
        gsum[cur]++;
    }
    else if (f[cur].ct == 'H')
    {
        hsum[cur]++;
    }
    for (int i = 0; i < f[cur].s.size(); i++)
    {
        presum(f[cur].s.at(i), cur);
    }
}
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
int main()
{
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].ct;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        r[u].push_back(v);
        r[v].push_back(u);
    }
    lg2[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }

    broot(1, 0);
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= lg2[dep[i]]; j++)
        {
            info[i][j] = info[info[i][j - 1]][j - 1];
        }
    }
    presum(1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        char cw;
        cin >> u >> v >> cw;
        int lc = lca(u, v);
        //cout << lc << " ";
        if (cw == 'G')
        {
            if (gsum[u] + gsum[v] - gsum[lc] - gsum[f[lc].fa] > 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        else if (cw == 'H')
        {
            if (hsum[u] + hsum[v] - hsum[lc] - hsum[f[lc].fa] > 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        //cout << endl;
    }
    return 0;
}