#include <bits/stdc++.h>
using namespace std;
int m[105][105];
bool b[105][105][105][105]; //x1,y1,x2,y2
bool c[105][105];
vector<pair<int, int>> cow;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, k, r;
void func(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    int sn = m[x][y];
    bool v[105][105] = {false};
    v[x][y] = true;
    while (!q.empty())
    {
        int kx = q.front().first;
        int ky = q.front().second;
        if ((kx != x || ky != y) && m[kx][ky] != 0)
        {
            c[sn][m[kx][ky]] = true;
            c[m[kx][ky]][sn] = true;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = kx + dx[i];
            int ny = ky + dy[i];
            if (nx <= n && nx > 0 && ny <= n && ny > 0)
            {
                if (!b[kx][ky][nx][ny] && !v[nx][ny])
                {
                    v[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        q.pop();
    }
}
int main()
{
    //freopen("countcross.in", "r", stdin);
    //freopen("countcross.out", "w", stdout);
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        b[x1][y1][x2][y2] = true;
        b[x2][y2][x1][y1] = true;
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        cow.push_back({x, y});
        m[x][y] = i + 1;
    }
    for (int i = 0; i < k; i++)
    {
        func(cow[i].first, cow[i].second);
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = i + 1; j <= k; j++)
        {
            if (!c[i][j] && !c[j][i])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}