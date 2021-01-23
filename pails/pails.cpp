#include <bits/stdc++.h>
using namespace std;
int x, y, k, m;
int ans = 1000000000;
bool v[105][105][105];
void dfs(int kx, int ky, int dep)
{
    if (v[kx][ky][dep])
    {
        return;
    }
    v[kx][ky][dep] = true;
    ans = min(ans, abs(m - (kx + ky)));
    if (dep == k)
    {
        return;
    }
    dfs(0, ky, dep + 1);
    dfs(kx, 0, dep + 1);
    dfs(x, ky, dep + 1);
    dfs(kx, y, dep + 1);
    dfs(kx + min(ky, x - kx), ky - min(ky, x - kx), dep + 1);
    dfs(kx - min(kx, y - ky), ky + min(kx, y - ky), dep + 1);
}
int main()
{
    //freopen("pails.in", "r", stdin);
    //freopen("pails.out", "w", stdout);
    cin >> x >> y >> k >> m;
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}