#include <iostream>
using namespace std;
int r, c;
char m[20][20];
int cache[20][20][2];
int dfs(int x, int y)
{
    if (x == r - 1 && y == c - 1)
    {
        return 1;
    }
    if (m[x][y] == 'R' && cache[x][y][0] != 0)
    {
        return cache[x][y][0];
    }
    else if (m[x][y] == 'B' && cache[x][y][1] != 0)
    {
        return cache[x][y][1];
    }
    int tmp = 0;
    for (int i = x + 1; i < r; i++)
    {
        for (int j = y + 1; j < c; j++)
        {
            if (m[x][y] != m[i][j])
            {
                tmp += dfs(i, j);
            }
        }
    }
    if (m[x][y] == 'R')
    {
        cache[x][y][0] = tmp;
    }
    else if (m[x][y] == 'B')
    {
        cache[x][y][1] = tmp;
    }
    return tmp;
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
        }
    }
    cout << dfs(0, 0) << endl;
    return 0;
}