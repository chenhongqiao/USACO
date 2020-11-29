#include <iostream>
using namespace std;
bool u[10][10];
int ans = 0;
int k;
short int dirx[4] = {1, -1, 0, 0};
short int diry[4] = {0, 0, 1, -1};
void dfs(int x1, int y1, int x2, int y2, int d)
{
    if (x1 < 1 || y1 < 1 || x2 < 1 || y2 < 1 || x1 > 5 || y1 > 5 || x2 > 5 || y2 > 5 || (x1 == x2 && y1 == y2))
    {
        if (x1 == x2 && y1 == y2 && d == 25 - k - 1)
        {
            ans++;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!u[x1 + dirx[i]][y1 + diry[i]] && !u[x2 + dirx[j]][y2 + diry[j]])
            {
                u[x1 + dirx[i]][y1 + diry[i]] = true;
                u[x2 + dirx[j]][y2 + diry[j]] = true;
                dfs(x1 + dirx[i], y1 + diry[i], x2 + dirx[j], y2 + diry[j], d + 2);
                u[x1 + dirx[i]][y1 + diry[i]] = false;
                u[x2 + dirx[j]][y2 + diry[j]] = false;
            }
        }
    }
}
int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        u[a][b] = true;
    }
    u[1][1] = true;
    u[5][5] = true;
    dfs(1, 1, 5, 5, 0);
    cout << ans << endl;
    return 0;
}