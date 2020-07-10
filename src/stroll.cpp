#include <iostream>
using namespace std;
int p;
struct nodes
{
    int ls, rs;
} n[1005];
int ans = 0;
void dfs(int dep, int fa)
{
    if (fa == 0)
    {
        ans = max(ans, dep);
        return;
    }
    dfs(dep + 1, n[fa].rs);
    dfs(dep + 1, n[fa].ls);
}
int main()
{
    cin >> p;
    for (int i = 0; i < p - 1; i++)
    {
        int fa, tls, trs;
        cin >> fa >> tls >> trs;
        n[fa].ls = tls;
        n[fa].rs = trs;
    }
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}