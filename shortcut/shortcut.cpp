// Shortcut
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, t;
vector<pair<int, int>> g[10005];
int p[10005];
vector<int> tree[10005];
int c[10005];
int d[10005];
priority_queue<pair<int, int>> q;
bool v[10005] = {false};
int cr[10005];
int dfs(int k)
{
    int cnt = 0;
    for (int u : tree[k])
    {
        if (!v[u])
        {
            v[u] = true;
            cnt += dfs(u);
        }
    }
    cr[k] = cnt + c[k];
    return cnt + c[k];
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 2; i <= n; i++)
    {
        d[i] = 1000000005;
    }
    q.push({0, 1});
    while (!q.empty())
    {
        int a = q.top().second;
        if (!v[a])
        {
            v[a] = true;
            for (auto u : g[a])
            {
                int b = u.first;
                int w = u.second;
                if (d[a] + w < d[b])
                {
                    p[b] = a;
                    d[b] = d[a] + w;
                    q.push({-d[b], b});
                }
                else if (d[a] + w == d[b] && a < p[b])
                {
                    p[b] = a;
                }
            }
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        tree[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        v[i] = false;
    }
    dfs(1);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, (long long)cr[i] * (d[i] - t));
    }
    cout << ans << endl;
    return 0;
}