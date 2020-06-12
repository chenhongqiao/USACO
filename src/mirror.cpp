#include <iostream>
using namespace std;
char f[1005][1005];
//int c[1005][1005][3][3];
int n, m;
int light(int x, int y, int xd, int yd, int dep)
{
    if (dep != 0 && f[x][y] == '\000')
    {
        return 0;
    }
    //if (c[x][y][xd + 1][yd + 1] != 0)
    //{
    // return c[x][y][xd + 1][yd + 1];
    // }
    if (f[x][y] == '/')
    {
        //int oxd = xd + 1, oyd = yd + 1;
        int tmp = xd;
        xd = -yd;
        yd = -tmp;
        //c[x][y][oxd][oyd] = light(x + xd, y + yd, xd, yd) + 1;
        //return c[x][y][oxd][oyd];
        return light(x + xd, y + yd, xd, yd, dep + 1) + 1;
    }
    else if (f[x][y] == '\\')
    {
        //int oxd = xd + 1, oyd = yd + 1;
        int tmp = xd;
        xd = yd;
        yd = tmp;
        //c[x][y][oxd][oyd] = light(x + xd, y + yd, xd, yd) + 1;
        //return c[x][y][oxd][oyd];
        return light(x + xd, y + yd, xd, yd, dep + 1) + 1;
    }
    else
    {
        return light(x + xd, y + yd, xd, yd, dep + 1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> f[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, light(i, 1, 0, 1, 0));
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, light(i, m, 0, -1, 0));
    }
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, light(1, i, 1, 0, 0));
    }
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, light(n, i, -1, 0, 0));
    }
    cout << ans << endl;
    return 0;
}