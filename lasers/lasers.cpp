#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
int n;
int lx, ly;
int bx, by;
struct fence
{
    int x, y;
};
vector<fence> f;
umap<int, map<int, int>> c;
umap<int, map<int, int>> r;
/*
    d=1 => right
    d=2 => up
    d=3 => left
    d=4 => down
*/
int ans = 1000000000;
bool vis[100005][5];
void dfs(int x, int y, int d, int v)
{
    if (x == bx && y == by)
    {
        ans = min(ans, v);
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (abs(d - i) == 2)
        {
            continue;
        }
        int ni = -1;
        if (i == 1)
        {
            auto nxt = r[y].upper_bound(x);
            if (nxt != r[y].end())
            {
                ni = nxt->second;
            }
        }
        else if (i == 2)
        {
            auto nxt = c[x].upper_bound(y);
            if (nxt != c[x].end())
            {
                ni = nxt->second;
            }
        }
        else if (i == 3)
        {
            auto nxt = r[y].lower_bound(x);
            if (nxt != r[y].begin())
            {
                nxt--;
                ni = nxt->second;
            }
        }
        else if (i == 4)
        {
            auto nxt = c[x].lower_bound(y);
            if (nxt != c[x].begin())
            {
                nxt--;
                ni = nxt->second;
            }
        }
        if (ni != -1 && !vis[ni][i])
        {
            if (ni != n)
            {
                vis[ni][i] = true;
            }
            dfs(f[ni].x, f[ni].y, i, v + (i == d || d == -10 ? 0 : 1));
        }
    }
}
int main()
{
    //freopen("lasers.in", "r", stdin);
    //freopen("lasers.out", "w", stdout);
    cin >> n >> lx >> ly >> bx >> by;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        f.push_back({x, y});
        c[x][y] = i;
        r[y][x] = i;
    }
    f.push_back({bx, by});
    c[bx][by] = n;
    r[by][bx] = n;
    dfs(lx, ly, -10, 0);
    cout << ans << endl;
    return 0;
}