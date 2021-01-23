#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, long long>> g[1005];
vector<pair<int, int>> c;
bool check(long long p)
{
    bool v[1005] = {false};
    v[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int f = q.front();
        for (int i = 0; i < g[f].size(); i++)
        {
            if (g[f][i].second <= p && !v[g[f][i].first])
            {
                v[g[f][i].first] = true;
                q.push(g[f][i].first);
            }
        }
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    //freopen("moocast.in", "r", stdin);
    //freopen("moocast.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        c.push_back({x, y});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long one = 1;
            long long d = one * abs(c[i].first - c[j].first) * abs(c[i].first - c[j].first) + one * abs(c[i].second - c[j].second) * abs(c[i].second - c[j].second);
            g[i].push_back({j, d});
            g[j].push_back({i, d});
        }
    }
    int h = 0, t = 625000000;
    while (h < t - 1)
    {
        int p = (h + t + 1) / 2;
        if (check(p))
        {
            t = p;
            continue;
        }
        else
        {
            h = p;
            continue;
        }
    }
    cout << t << endl;
    return 0;
}