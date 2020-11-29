#include <iostream>
using namespace std;
int n, m;
char p[105][105];
bool u[105][105];
int dir[4] = {1, -1, 0};
void func(int x, int y)
{
    if (p[x][y] == '.' || x < 0 || y < 0 || x >= n || y >= m)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!u[x + dir[i]][y + dir[j]])
            {
                u[x + dir[i]][y + dir[j]] = true;
                func(x + dir[i], y + dir[j]);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (p[i][j] == 'W' && !u[i][j])
            {
                u[i][j] = true;
                ans++;
                func(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}