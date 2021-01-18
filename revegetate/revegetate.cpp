#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, char>> g[100005];
int c[100005];
void dfs(int f, int l, char lt, int dep)
{
    if (dep != 0)
    {
        if (lt == 'S')
        {
            if (c[f] == 0)
            {
                c[f] = l;
            }
            else
            {
                if (c[f] != l)
                {
                    cout << 0 << endl;
                    exit(0);
                }
                return;
            }
        }
        else if (lt == 'D')
        {
            if (c[f] == 0)
            {
                c[f] = -l;
            }
            else
            {
                if (c[f] == l)
                {
                    cout << 0 << endl;
                    exit(0);
                }
                return;
            }
        }
    }
    for (int i = 0; i < g[f].size(); i++)
    {
        dfs(g[f][i].first, c[f], g[f][i].second, dep + 1);
    }
}
int main()
{
    //freopen("revegetate.in", "r", stdin);
    //freopen("revegetate.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char t;
        cin >> t >> a >> b;
        g[a].push_back({b, t});
        g[b].push_back({a, t});
    }
    vector<int> ans;
    ans.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 0)
        {
            c[i] = 1;
            dfs(i, 1, ' ', 0);
            ans.push_back(0);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}