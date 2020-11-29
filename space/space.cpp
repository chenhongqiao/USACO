#include <iostream>
using namespace std;
int n;
char p[1005][1005];
bool u[1005][1005];
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
void func(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        if (!(x + dirx[i] < 0 || y + diry[i] < 0 || x + dirx[i] >= n || y + diry[i] >= n || p[x + dirx[i]][y + diry[i]] == '.') && !u[x + dirx[i]][y + diry[i]])
        {
            u[x + dirx[i]][y + diry[i]] = true;
            func(x + dirx[i], y + diry[i]);
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
            cin >> p[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i][j] == '*' && !u[i][j])
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