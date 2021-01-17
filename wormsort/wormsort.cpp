#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[100005];
vector<pair<int, int>> g[100005];
void dfs(int cm[], bool v[], int f, const int color, const int x)
{
    cm[f] = color;
    for (int i = 0; i < g[f].size(); i++)
    {
        if (!v[g[f][i].first] && g[f][i].second >= x)
        {
            v[g[f][i].first] = true;
            dfs(cm, v, g[f][i].first, color, x);
        }
    }
}
bool check(int x)
{
    int cm[100005] = {0};
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (cm[i] == 0)
        {
            bool v[100005] = {false};
            dfs(cm, v, i, cnt, x);
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cm[i] != cm[c[i]])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    //freopen("wormsort.in", "r", stdin);
    //freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    bool st = true;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] != i)
        {
            st = false;
            break;
        }
    }
    if (st)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    int h = 0, t = 1000000000;
    while (h < t - 1)
    {
        int p = (h + t + 1) / 2;
        if (!check(p))
        {
            t = p;
        }
        else
        {
            h = p;
        }
    }
    cout << h << endl;
    return 0;
}