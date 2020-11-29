#include <iostream>
#include <vector>
using namespace std;
char s[55][55];
bool u[55][55];
vector<pair<int, int>> l[2];
int n, m;
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};
void func(int x, int y, int t)
{
    bool edge = false;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dirx[i];
        int ny = y + diry[i];
        if (!u[nx][ny])
        {
            if (!(nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '.'))
            {
                u[nx][ny] = true;
                func(nx, ny, t);
            }
            else
            {
                edge = true;
            }
        }
    }
    if (edge)
    {
        l[t].push_back({x, y});
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
        }
    }
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'X' && !u[i][j])
            {
                u[i][j] = true;
                func(i, j, t);
                t++;
            }
        }
    }
    int ans = 100000000;
    for (int i = 0; i < l[0].size(); i++)
    {
        for (int j = 0; j < l[1].size(); j++)
        {
            // cout << l[0][i].first << "," << l[0][i].second << " " << l[1][j].first << "," << l[1][j].second << endl;
            ans = min(ans, abs(l[0][i].first - l[1][j].first) + abs(l[0][i].second - l[1][j].second) - 1);
        }
    }
    cout << ans << endl;
    return 0;
}