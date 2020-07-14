#include <iostream>
using namespace std;
int n, m;
char s[755][755];
bool u[755][755];
int dir[3] = {0, 1, -1};
int func(int x, int y)
{
    int tmp = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int nx = x + dir[i];
            int ny = y + dir[j];
            if (!(nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '*') && !u[nx][ny])
            {
                u[nx][ny] = true;
                tmp += func(nx, ny);
            }
        }
    }
    return tmp + 1;
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!u[i][j] && s[i][j] == '.')
            {
                u[i][j] = true;
                ans = max(ans, func(i, j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}