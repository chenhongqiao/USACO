// Bessie's Dream
#include <iostream>
#include <queue>
using namespace std;
short int g[1005][1005];
bool v[1005][1005][4][2];
short int dx[4] = {1, -1, 0, 0};
short int dy[4] = {0, 0, 1, -1};
struct state
{
    int x, y, d, s, ans;
};
template class std::queue<state>;
int n, m;
bool on_board(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }

    return false;
}

int main()
{
    std::queue<state> q;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    v[0][0][0][0] = true;
    v[0][0][1][0] = true;
    v[0][0][2][0] = true;
    v[0][0][3][0] = true;
    q.push({0, 0, -1, 0, 0});
    int ans = 1000000007;

    while (!q.empty())
    {
        state h = q.front();

        if (h.x == n - 1 && h.y == m - 1)
        {
            ans = min(ans, h.ans);
        }

        if (g[h.x][h.y] == 4)
        {
            h.s = 0;

            if (on_board(h.x + dx[h.d], h.y + dy[h.d]) && g[h.x + dx[h.d]][h.y + dy[h.d]] != 0 && g[h.x + dx[h.d]][h.y + dy[h.d]] != 3)
            {
                if (!v[h.x + dx[h.d]][h.y + dy[h.d]][h.d][h.s])
                {
                    q.push({h.x + dx[h.d], h.y + dy[h.d], h.d, h.s, h.ans + 1});
                    v[h.x + dx[h.d]][h.y + dy[h.d]][h.d][h.s] = true;
                }

                q.pop();
                continue;
            }
        }

        if (g[h.x][h.y] == 2)
        {
            h.s = 1;
        }

        for (int i = 0; i < 4; i++)
        {
            int kx = h.x + dx[i];
            int ky = h.y + dy[i];

            if (on_board(kx, ky) && !v[kx][ky][i][h.s])
            {
                if (g[kx][ky] == 1 || g[kx][ky] == 2 || g[kx][ky] == 4)
                {
                    q.push({kx, ky, i, h.s, h.ans + 1});
                    v[kx][ky][i][h.s] = true;
                }
                else if (g[kx][ky] == 3 && h.s == 1)
                {
                    q.push({kx, ky, i, h.s, h.ans + 1});
                    v[kx][ky][i][h.s] = true;
                }
            }
        }

        q.pop();
    }

    if (ans == 1000000007)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}
