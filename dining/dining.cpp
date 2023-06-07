// Fine Dining
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, k;
struct edge
{
    int v, w;
};
struct node
{
    int dis, u;
    bool operator>(const node &a) const
    {
        return dis > a.dis;
    }
};
struct haybale
{
    int u, w;
};
vector<edge> g[50005];
vector<haybale> h;
int dis[50005];
int disf[50005];
bool vis[50005];
priority_queue<node, vector<node>, greater<node>> q;
int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (int i = 0; i < k; i++)
    {
        int u, w;
        cin >> u >> w;
        h.push_back({u, w});
    }

    fill(dis, dis + n + 5, 1000000007);
    dis[n] = 0;
    q.push({0, n});

    while (!q.empty())
    {
        int u = q.top().u;
        q.pop();

        if (vis[u])
            continue;

        vis[u] = true;

        for (auto ed : g[u])
        {
            int v = ed.v;
            int w = ed.w;

            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }

    while (!g[n].empty())
    {
        g[n + 1].push_back(g[n].back());
        g[n].pop_back();
    }

    for (int i = 0; i < k; i++)
    {
        g[h[i].u].push_back({n + 1, dis[h[i].u]});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            if (g[i][j].v == n)
            {
                g[i][j].v = n + 1;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        int u = h[i].u;
        int w = h[i].w;
        g[n].push_back({u, dis[u] - w});
    }

    fill(disf, disf + n + 5, 1000000007);
    fill(vis, vis + n + 5, false);

    while (!q.empty())
        q.pop();
    disf[n] = 0;
    q.push({0, n});

    while (!q.empty())
    {
        int u = q.top().u;
        q.pop();

        if (vis[u])
            continue;

        vis[u] = true;

        for (auto ed : g[u])
        {
            int v = ed.v;
            int w = ed.w;

            if (disf[v] > disf[u] + w)
            {
                disf[v] = disf[u] + w;
                q.push({disf[v], v});
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (disf[i] <= dis[i])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}
