#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[100005];
bool v[100005];
char cow[100005];
int color[100005];
void dfs(int f, const char t, int mark)
{
    color[f] = mark;
    for (int i = 0; i < g[f].size(); i++)
    {
        if (!v[g[f][i]] && cow[g[f][i]] == t)
        {
            v[g[f][i]] = true;
            dfs(g[f][i], t, mark);
        }
    }
}
int main()
{
    //freopen("milkvisits.in", "r", stdin);
    //freopen("milkvisits.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cow[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            dfs(i, cow[i], cnt);
            cnt++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char t;
        cin >> a >> b >> t;
        if (cow[a] != t && cow[b] != t && color[a] == color[b])
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }

    return 0;
}