#include <bits/stdc++.h>
using namespace std;
set<int> b[55];
vector<int> g[55];
int dis[50005];
int p[50005];
bool ba[55];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen64("6.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        dis[i] = 1000000005;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        b[p[i]].insert(i);
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            char c;
            cin >> c;
            if (c == '1')
            {
                g[i].push_back(j);
            }
        }
    }
    q.push({0, 0});
    int cnt = 0;
    while (!q.empty())
    {
        int kp = q.top().second;
        int kd = q.top().first;
        int kb = p[kp];
        if (kb == 49)
        {
            cnt++;
        }
        ba[kb] = true;
        for (int i = 0; i < g[kb].size(); i++)
        {
            auto itb = b[g[kb][i]].lower_bound(kp);
            if (itb != b[g[kb][i]].begin())
            {
                itb--;
                int np = *itb;
                int d = kd + abs(kp - np);
                if (d < dis[np])
                {
                    dis[np] = d;
                    q.push({d, np});
                }
            }

            auto ita = b[g[kb][i]].upper_bound(kp);
            if (ita != b[g[kb][i]].end())
            {
                int np = *ita;
                int d = kd + abs(kp - np);
                if (d < dis[np])
                {
                    dis[np] = d;
                    q.push({d, np});
                }
            }
        }
        q.pop();
    }
    if (dis[n - 1] == 1000000005)
    {

        cout << -1 << endl;
    }
    else
    {
        cout << dis[n - 1] << endl;
    }
    return 0;
}