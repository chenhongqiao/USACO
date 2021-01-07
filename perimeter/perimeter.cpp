#include <iostream>
using namespace std;
int n;
char m[1105][1105];
bool u[1105][1105];
int a, p;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
void func(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
    {
        p++;
        return;
    }
    if (u[x][y])
    {
        return;
    }
    if (m[x][y] == '.')
    {
        p++;
        return;
    }
    a++;
    u[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        func(x + dirx[i], y + diry[i]);
    }
}
int main()
{
    //freopen("perimeter.in", "r", stdin);
    //freopen("perimeter.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    int ansa = 0, ansp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == '#' && !u[i][j])
            {
                a = 0;
                p = 0;
                func(i, j);
                if (a > ansa)
                {
                    ansa = a;
                    ansp = p;
                }
                else if (a == ansa && p < ansp)
                {
                    ansp = p;
                }
            }
        }
    }
    cout << ansa << " " << ansp << endl;
    return 0;
}