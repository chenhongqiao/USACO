#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<pair<int, int>> g[100005];
void dijkstra()
{
    bool v[100005] = {false};
    int d[100005] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (i != s)
        {
            d[i] = 2147483647;
        }
    }
    priority_queue<pair<int, int>> q;
    d[s] = 0;
    q.push({-2147483647, s});
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
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }
    dijkstra();
    return 0;
}