#include <iostream>
using namespace std;
int n;
char m[10][10];
bool u[10][10];
short int xdir[4] = {0, 1, 0, -1};
short int ydir[4] = {1, 0, -1, 0};
int ans = 0;
void dfs(int ln, int rn, int x, int y)
{
    if ((rn != 0 && rn >= ln) || x < 0 || y < 0 || x >= n || y >= n)
    {
        if (ln == rn)
        {
            ans = max(ans, ln + rn);
        }
        return;
    }
    if (rn != 0 && m[x][y] == '(')
    {
        return;
    }
    if (m[x][y] == '(')
    {
        ln++;
    }
    else if (m[x][y] == ')')
    {
        rn++;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!u[x + xdir[i]][y + ydir[i]])
        {
            u[x + xdir[i]][y + ydir[i]] = true;
            dfs(ln, rn, x + xdir[i], y + ydir[i]);
            u[x + xdir[i]][y + ydir[i]] = false;
        }
    }
}
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    u[0][0] = true;
    dfs(0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}