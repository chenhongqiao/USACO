#include <bits/stdc++.h>
using namespace std;
char p[105][105];
int c[105][105];
bool v[105][105];
int dx[4] = {0, 1, -1};
int dy[4] = {1, -1, 0};
int main()
{
    int x, y;
    int mx, my;
    cin >> y >> x >> my >> mx;
    mx = x - mx + 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            cin >> p[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({mx, my});
    c[mx][my] = 0;
    v[mx][my] = true;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (p[cx + dx[i]][cy + dy[j]] == '.' && !v[cx + dx[i]][cy + dy[j]])
                {
                    q.push({cx + dx[i], cy + dy[j]});
                    v[cx + dx[i]][cy + dy[j]] = true;
                    c[cx + dx[i]][cy + dy[j]] = c[cx][cy] + 1;
                }
            }
        }
        q.pop();
    }
    int ans = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            ans = max(ans, c[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}