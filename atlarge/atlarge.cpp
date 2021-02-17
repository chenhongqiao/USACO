#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> g[100005];
int dist[100005];
bool vis[100005];
int dfs(int f, int dep)
{
    if (dist[f] != -1)
    {
        return dist[f];
    }
    int tmp = 1000000005;
    int cnt = 0;
    for (int i = 0; i < g[f].size(); i++)
    {
        if (!vis[g[f][i]])
        {
            cnt++;
            vis[g[f][i]] = true;
            tmp = min(tmp, dfs(g[f][i], dep + 1) + 1);
            vis[g[f][i]] = false;
        }
    }
    if (cnt == 0)
    {
        tmp = 0;
    }
    dist[f] = tmp;
    return tmp;
}
int main()
{
    //freopen("atlarge.in", "r", stdin);
    //freopen("atlarge.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (g[k].size() == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = -1;
    }
    vis[k] = true;
    dfs(k, 0);
    queue<pair<int, int>> q;
    q.push({k, 0});
    int ans = 0;
    bool v[100005] = {false};
    v[k] = true;
    while (!q.empty())
    {
        int f = q.front().first;
        int d = q.front().second;
        for (int i = 0; i < g[f].size(); i++)
        {
            if (!v[g[f][i]])
            {
                v[g[f][i]] = true;
                if (dist[g[f][i]] <= d + 1)
                {
                    ans++;
                }
                else
                {
                    q.push({g[f][i], d + 1});
                }
            }
        }
        q.pop();
    }
    cout << ans << endl;
    return 0;
}