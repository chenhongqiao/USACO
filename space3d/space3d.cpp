#include <bits/stdc++.h>
using namespace std;
int b[105][105][105];
char c[105][105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct rock
{
    int z, x, y;
};
int n;
void floodfill(int z, int x, int y, int v)
{
    queue<rock> q;
    q.push({z, x, y});
    b[z][x][y] = v;
    while (!q.empty())
    {
        int cz = q.front().z;
        int cx = q.front().x;
        int cy = q.front().y;
        for (int i = 0; i < 4; i++)
        {
            if (c[cz][cx + dx[i]][cy + dy[i]] == '*' && b[cz][cx + dx[i]][cy + dy[i]] == 0)
            {
                b[cz][cx + dx[i]][cy + dy[i]] = v;
                q.push({cz, cx + dx[i], cy + dy[i]});
            }
        }
        if (cz - 1 >= 0 && c[cz - 1][cx][cy] == '*' && b[cz - 1][cx][cy] == 0)
        {
            b[cz - 1][cx][cy] = v;
            q.push({cz - 1, cx, cy});
        }
        if (cz + 1 < n && c[cz + 1][cx][cy] == '*' && b[cz + 1][cx][cy] == 0)
        {
            b[cz + 1][cx][cy] = v;
            q.push({cz + 1, cx, cy});
        }
        q.pop();
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> c[i][j][k];
            }
        }
    }
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (c[i][j][k] == '*' && b[i][j][k] == 0)
                {
                    floodfill(i, j, k, cnt);
                    cnt++;
                }
            }
        }
    }

    cout << cnt - 1 << endl;
    return 0;
}
