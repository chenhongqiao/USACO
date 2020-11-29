#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
struct cow
{
    int x, y;
} c[100005];
vector<int> G[100005];
int tx, ty, lx, ly;
bool vis[100005];
void upload(int fa)
{
    tx = max(tx, c[fa].x);
    ty = max(ty, c[fa].y);
    lx = min(lx, c[fa].x);
    ly = min(ly, c[fa].y);
}
void bfs(int fa)
{
    queue<int> q;
    q.push(fa);
    vis[fa] = true;
    while (!q.empty())
    {
        int obj = q.front();
        upload(obj);
        for (int i = 0; i < G[obj].size(); i++)
        {
            if (!vis[G[obj][i]])
            {
                vis[G[obj][i]] = true;
                q.push(G[obj][i]);
            }
        }
        q.pop();
    }
}
int main()
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i].x >> c[i].y;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 800000000;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            tx = -100;
            ty = -100;
            lx = 200000000;
            ly = 200000000;
            bfs(i);
            ans = min(ans, ((tx - lx) * 2) + ((ty - ly) * 2));
        }
    }
    cout << ans << endl;
    return 0;
}