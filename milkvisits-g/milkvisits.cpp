// Milk Visits
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n, m;
int t[100005];
vector<int> g[100005];
int preid[100005];
int postid[100005];
int precnt = 1;
int postcnt = 1;
struct query
{
    int b, c, id;
};
bool ans[100005];
vector<query> q[100005];
int dep[100005];
int fa[100005][25];
void process(int rt, int f)
{
    preid[rt] = precnt++;
    fa[rt][0] = f;
    dep[rt] = dep[f] + 1;
    for (int i = 1; i <= 20; i++)
    {
        fa[rt][i] = fa[fa[rt][i - 1]][i - 1];
    }
    for (auto i = g[rt].begin(); i != g[rt].end(); i++)
    {
        if (*i != f)
        {
            process(*i, rt);
        }
    }
    postid[rt] = postcnt++;
}

bool is_ancestor(int a, int b)
{
    return preid[a] < preid[b] && postid[a] > postid[b];
}
int lca(int a, int b)
{
    if (dep[a] > dep[b])
    {
        swap(a, b);
    }
    int dis = dep[b] - dep[a];
    for (int i = 0; dis; i++, dis >>= 1)
    {
        if (dis & 1)
        {
            b = fa[b][i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 20; i >= 0 && a != b; i--)
    {
        if (fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    if (a != b)
    {
        return fa[a][0];
    }
    else
    {
        return a;
    }
}
stack<int> c[100005];
void dfs(int rt, int f)
{
    c[t[rt]].push(rt);
    for (auto i = q[rt].begin(); i != q[rt].end(); i++)
    {
        int a = rt, b = i->b;
        int l = lca(a, b);
        if (!c[i->c].empty() && !is_ancestor(c[i->c].top(), l))
        {
            ans[i->id] = true;
        }
    }
    for (auto i = g[rt].begin(); i != g[rt].end(); i++)
    {
        if (*i != f)
        {
            dfs(*i, rt);
        }
    }
    c[t[rt]].pop();
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        q[a].push_back({b, c, i});
        q[b].push_back({a, c, i});
    }
    process(1, 0);
    dfs(1, 0);
    for (int i = 0; i < m; i++)
    {
        if (ans[i])
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}
