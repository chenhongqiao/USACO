// Replication
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define f first
#define s second
using namespace std;

int n, d;
char g[1005][1005];
int rd[1005][1005];
bool cp[1005][1005] = {false};
bool ans[1005][1005] = {false};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void build_rd()
{
    struct cell
    {
        int x, y, d;
    };
    queue<cell> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == '#')
            {
                q.push({i, j, 0});
            }
        }
    }

    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int kx = q.front().x + dx[i];
            int ky = q.front().y + dy[i];

            if (kx >= 0 && kx < n && ky >= 0 && ky < n && rd[kx][ky] == -1)
            {
                rd[kx][ky] = q.front().d + 1;
                q.push({kx, ky, rd[kx][ky]});
            }
        }

        q.pop();
    }
}

void bfs()
{
    struct cell
    {
        int x, y, t;
    };
    queue<cell> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 'S')
            {
                cp[i][j] = true;
                q.push({i, j, 0});
            }
        }
    }

    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int kx = q.front().x + dx[i];
            int ky = q.front().y + dy[i];
            int kt = q.front().t + 1;

            if (kx >= 0 && kx < n && ky >= 0 && ky < n && g[kx][ky] != '#' && !cp[kx][ky] && kt / d <= rd[kx][ky])
            {
                cp[kx][ky] = true;

                if (kt / d + 1 <= rd[kx][ky])
                {
                    q.push({kx, ky, kt});
                }
            }
        }

        q.pop();
    }
}

void fill_cells()
{
    struct cell
    {
        int x, y, d;
    };
    auto comp = [](cell a, cell b)
    {
        return a.d < b.d;
    };
    priority_queue<cell, vector<cell>, decltype(comp)> q(comp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cp[i][j])
            {
                q.push({i, j, rd[i][j]});
                ans[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        int nd = q.top().d;

        if (nd > 1)
        {
            for (int i = 0; i < 4; i++)
            {
                int kx = q.top().x + dx[i];
                int ky = q.top().y + dy[i];

                if (kx >= 0 && kx < n && ky >= 0 && ky < n && g[kx][ky] != '#' && !ans[kx][ky])
                {
                    ans[kx][ky] = true;
                    q.push({kx, ky, nd - 1});
                }
            }
        }

        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            rd[i][j] = -1;
        }
    }

    build_rd();
    bfs();
    fill_cells();

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j])
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
