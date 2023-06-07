// Cow Navigation
#include <iostream>
#include <queue>
using namespace std;
int n;
char g[25][25];
bool v[25][25][4][25][25][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
struct node
{
    const int x1, y1, d1, x2, y2, d2, dep;
};
queue<node> q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    q.push({0, n - 1, 0, 0, n - 1, 1, 0});
    while (!q.empty())
    {
        auto h = q.front();
        const int x1 = h.x1, y1 = h.y1, d1 = h.d1, x2 = h.x2, y2 = h.y2, d2 = h.d2, dep = h.dep;
        if (x1 == n - 1 && y1 == 0 && x2 == n - 1 && y2 == 0)
        {
            cout << dep << endl;
            return 0;
        }
        v[x1][y1][d1][x2][y2][d2] = true;
        v[x2][y2][d2][x1][y1][d1] = true;
        if (!v[x1][y1][(d1 + 3) % 4][x2][y2][(d2 + 3) % 4])
        {
            q.push({x1, y1, (d1 + 3) % 4, x2, y2, (d2 + 3) % 4, dep + 1});
        }
        if (!v[x1][y1][(d1 + 1) % 4][x2][y2][(d2 + 1) % 4])
        {
            q.push({x1, y1, (d1 + 1) % 4, x2, y2, (d2 + 1) % 4, dep + 1});
        }
        int nx1 = x1 + dx[d1], ny1 = y1 + dy[d1], nx2 = x2 + dx[d2], ny2 = y2 + dy[d2];
        if ((x1 == n - 1 && y1 == 0) || nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n || g[ny1][nx1] == 'H')
        {
            nx1 = x1;
            ny1 = y1;
        }
        if ((x2 == n - 1 && y2 == 0) || nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n || g[ny2][nx2] == 'H')
        {
            nx2 = x2;
            ny2 = y2;
        }
        if (!v[nx1][ny1][d1][nx2][ny2][d2])
        {
            q.push({nx1, ny1, d1, nx2, ny2, d2, dep + 1});
        }
        q.pop();
    }
    return 0;
}