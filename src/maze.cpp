#include <iostream>
#include <algorithm>
using namespace std;
char ma[105][105];
bool u[105][105];
bool bad_way[105][105];
int n, m;
string dfs(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return "";
    }
    if (ma[x][y] == '#')
    {
        return "";
    }
    if (bad_way[x][y])
    {
        return "";
    }
    if (ma[x][y] == 'F')
    {
        return "g0ld";
    }
    if (!u[x + 1][y])
    {
        u[x + 1][y] = true;
        string s = dfs(x + 1, y);
        u[x + 1][y] = false;
        if (s.size() > 0)
        {
            if (s == "g0ld")
            {
                s = "";
            }
            return s + "D";
        }
        else
        {
            bad_way[x + 1][y] = true;
        }
    }
    if (!u[x - 1][y])
    {
        u[x - 1][y] = true;
        string s = dfs(x - 1, y);
        u[x - 1][y] = false;
        if (s.size() > 0)
        {
            if (s == "g0ld")
            {
                s = "";
            }
            return s + "U";
        }
        else
        {
            bad_way[x - 1][y] = true;
        }
    }
    if (!u[x][y + 1])
    {
        u[x][y + 1] = true;
        string s = dfs(x, y + 1);
        u[x][y + 1] = false;
        if (s.size() > 0)
        {
            if (s == "g0ld")
            {
                s = "";
            }
            return s + "R";
        }
        else
        {
            bad_way[x][y + 1] = true;
        }
    }
    if (!u[x][y - 1])
    {
        u[x][y - 1] = true;
        string s = dfs(x, y - 1);
        u[x][y - 1] = false;
        if (s.size() > 0)
        {
            if (s == "g0ld")
            {
                s = "";
            }
            return s + "L";
        }
        else
        {
            bad_way[x][y - 1] = true;
        }
    }
    return "";
}
string solve()
{
    cin >> n >> m;
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ma[i][j];
            if (ma[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }
    cout << sx << " " << sy << endl;
    u[sx][sy] = true;
    string s = dfs(sx, sy);
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    cout << solve() << endl;
}