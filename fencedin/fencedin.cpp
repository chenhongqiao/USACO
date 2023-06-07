// Fenced In
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge
{
    int u, v;
    long long w;
};
bool comp(const edge &a, const edge &b)
{
    return a.w < b.w;
}
int a, b, n, m;
vector<int> v;
vector<int> h;
int mp[2105][2105];
short int dx[4] = {1, -1, 0, 0};
short int dy[4] = {0, 0, 1, -1};
vector<edge> g;
//pair<int, int> dbg[4000005];
int th[4100005];
int f[4100005];
bool vis[4100005];
long long ans = 0;
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
    if (th[ra] < th[rb])
    {
        swap(ra, rb);
    }
    f[rb] = ra;
    th[ra] = max(th[ra], th[rb] + 1);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> n >> m;
    v.push_back(0);
    v.push_back(b);
    h.push_back(0);
    h.push_back(a);
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }
    for (int i = 0; i < m; i++)
    {
        int in;
        cin >> in;
        h.push_back(in);
    }
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    int cnt = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            mp[i][j] = cnt++;
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            int id = mp[i][j];
            vis[id] = true;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n + 1 || ny < 0 || ny >= m + 1)
                {
                    continue;
                }
                int aid = mp[nx][ny];
                if (vis[aid])
                {
                    continue;
                }
                int w = k < 2 ? h[j + 1] - h[j] : v[i + 1] - v[i];
                g.push_back({id, aid, w});
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        f[i] = i;
    }
    sort(g.begin(), g.end(), comp);
    for (edge e : g)
    {
        if (find(e.u) != find(e.v))
        {
            ans += e.w;
            unite(e.u, e.v);
        }
    }
    cout << ans << endl;
    return 0;
}