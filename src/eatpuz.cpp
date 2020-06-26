#include <iostream>
#include <algorithm>
using namespace std;
int f[25];
int ans = 0;
int c, b;
void dfs(int dep, int cn)
{
    if (dep >= b)
    {
        if (cn <= c)
        {
            ans = max(ans, cn);
        }
        return;
    }
    dfs(dep + 1, cn + f[dep]);
    dfs(dep + 1, cn);
}
int main()
{
    cin >> c >> b;
    for (int i = 0; i < b; i++)
    {
        cin >> f[i];
    }
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}