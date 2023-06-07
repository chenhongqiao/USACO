// Milking Order
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> od[50005];
vector<int> g[100005];
int vis[100005];
int d[100005];
int cnt[100005];
priority_queue<int, vector<int>, greater<int>> q;
vector<int> ans;
void init_graph()
{
    for (int i = 1; i <= n; i++)
    {
        while (!g[i].empty())
        {
            g[i].pop_back();
        }
    }
}
bool dfs(const int v, const int dep, const int rd)
{
    vis[v] = rd;
    d[v] = dep;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (vis[g[v][i]] == rd)
        {
            if (d[g[v][i]] < dep)
            {
                return false;
            }
        }
        else
        {
            if (!dfs(g[v][i], dep + 1, rd))
            {
                return false;
            }
        }
    }
    d[v] = 1000000005;
    return true;
}
bool check(int x)
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        d[i] = 1000000005;
    }
    init_graph();
    for (int i = 0; i < x; i++)
    {
        for (int j = 1; j < od[i].size(); j++)
        {
            g[od[i][j]].push_back(od[i][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (!dfs(i, 0, i))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int in;
            cin >> in;
            od[i].push_back(in);
        }
    }
    int h = 0, t = m;
    while (h < t - 1)
    {
        int x = (h + t) / 2;
        if (check(x))
        {
            h = x;
        }
        else
        {
            t = x;
        }
    }
    init_graph();
    for (int i = 0; i < h; i++)
    {
        for (int j = 1; j < od[i].size(); j++)
        {
            g[od[i][j - 1]].push_back(od[i][j]);
            cnt[od[i][j]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int hd = q.top();
        q.pop();
        ans.push_back(hd);
        for (int i = 0; i < g[hd].size(); i++)
        {
            cnt[g[hd][i]]--;
            if (cnt[g[hd][i]] == 0)
            {
                q.push(g[hd][i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}