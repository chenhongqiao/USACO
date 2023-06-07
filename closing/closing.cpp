// Closing the Farm
#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
vector<int> g[200005];
int h[200005];
int f[200005];
stack<int> seq;
stack<bool> ans;
unordered_set<int> s;
unordered_set<int> l;
int n, m;
int find(int v)
{
    if (f[v] != v)
    {
        f[v] = find(f[v]);
    }
    return f[v];
}

void unite(int a, int b)
{
    int ra = find(a);
    int rb = find(b);
    if (h[ra] > h[rb])
    {
        f[rb] = ra;
        s.erase(rb);
        s.insert(ra);
        h[ra] = max(h[ra], h[rb] + 1);
    }
    else
    {
        f[ra] = rb;
        s.erase(ra);
        s.insert(rb);
        h[rb] = max(h[rb], h[ra] + 1);
    }
}
void bfs(int v)
{
    s.insert(v);
    f[v] = v;
    queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        int t = q.front();
        int rt = find(t);
        for (int i = 0; i < g[t].size(); i++)
        {
            if (l.find(g[t][i]) != l.end() && rt != find(g[t][i]))
            {
                unite(rt, g[t][i]);
                q.push(g[t][i]);
            }
        }
        q.pop();
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        seq.push(v);
    }
    while (!seq.empty())
    {
        l.insert(seq.top());
        bfs(seq.top());
        if (s.size() > 1)
        {
            ans.push(false);
        }
        else
        {
            ans.push(true);
        }
        seq.pop();
    }
    while (!ans.empty())
    {
        if (ans.top())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        ans.pop();
    }
    return 0;
}