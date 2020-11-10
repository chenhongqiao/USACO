#include <bits/stdc++.h>
using namespace std;
int g[6][6];
map<int, bool> p;
int ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
const int n = 5, m = 5;
void func(int x, int y, int v, int dep)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return;
    }
    if (dep >= 6)
    {
        if (!p[v])
        {
            p[v] = true;
            ans++;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        func(x + dx[i], y + dy[i], v * 10 + g[x][y], dep + 1);
    }
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            func(i, j, 0, 0);
        }
    }
    cout << ans << endl;
    return 0;
}