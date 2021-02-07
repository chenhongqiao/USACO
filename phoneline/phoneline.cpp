#include <bits/stdc++.h>
using namespace std;
int n, p, k;
vector<pair<int, int>> g[1005];
multiset<int> s;
bool v[1005];
int ans = 1000000000;
void dfs(int f)
{
    auto it = s.rbegin();
    for (int i = 0; i < k && it != s.rend(); i++)
    {
        it++;
    }
    if (it != s.rend() && *it > ans)
    {
        return;
    }
    if (f == n)
    {
        if (s.size() <= k)
        {
            cout << 0 << endl;
            exit(0);
        }
        ans = min(ans, *it);
    }
    for (int i = 0; i < g[f].size(); i++)
    {
        if (!v[g[f][i].first])
        {
            v[g[f][i].first] = true;
            s.insert(g[f][i].second);
            dfs(g[f][i].first);
            v[g[f][i].first] = false;
            s.erase(s.lower_bound(g[f][i].second));
        }
    }
}
int main()
{
    cin >> n >> p >> k;
    for (int i = 0; i < p; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dfs(1);
    if (ans == 1000000000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}