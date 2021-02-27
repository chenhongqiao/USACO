#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[1005];
struct pipe
{
    int a, b;
    int c, f;
};
vector<pipe> p;
int n, m;
bool fcomp(pipe a, pipe b)
{
    return a.f > b.f;
}
int dijkstra()
{
    bool v[100005] = {false};
    int d[100005] = {0};
    for (int i = 2; i <= n; i++)
    {
        d[i] = 1000000000;
    }
    priority_queue<pair<int, int>> q;
    d[1] = 0;
    q.push({-1000000000, 1});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (v[a])
        {
            continue;
        }
        v[a] = true;
        for (int i = 0; i < g[a].size(); i++)
        {
            int b = g[a][i].first;
            int w = g[a][i].second;
            if (d[a] + w < d[b])
            {
                d[b] = d[a] + w;
                q.push({-d[b], b});
            }
        }
    }
    return d[n];
}
int main()
{
    //freopen("pump.in", "r", stdin);
    //freopen("pump.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        p.push_back({a, b, c, f});
    }
    sort(p.begin(), p.end(), fcomp);
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        int lf = p[i].f;
        g[p[i].a].push_back({p[i].b, p[i].c});
        g[p[i].b].push_back({p[i].a, p[i].c});
        int c = dijkstra();
        ans = max(ans, (long long)lf * 1000000 / c);
    }
    cout << ans << endl;
    return 0;
}