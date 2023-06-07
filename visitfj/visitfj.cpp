// Why Did the Cow Cross the Road
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int x, y;
};
int p[105][105];
int n, t;
long long d[105][105];
bool v[105][105];
auto comp = [](const pair<int, node> &a, const pair<int, node> &b)
{
    return a.first > b.first;
};
priority_queue<pair<int, node>, vector<pair<int, node>>, decltype(comp)> q(comp);
vector<pair<node, long long>> g[105][105];
bool on_grid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(n - 1 - i) + abs(n - 1 - j) < 3)
            {
                g[i][j].push_back({{n - 1, n - 1}, t * (abs(n - 1 - i) + abs(n - 1 - j))});
            }
            if (on_grid(i + 1, j))
            {
                g[i][j].push_back({{i + 1, j}, p[i + 1][j] + t * 3});
            }
            if (on_grid(i - 1, j))
            {
                g[i][j].push_back({{i - 1, j}, p[i - 1][j] + t * 3});
            }
            if (on_grid(i, j + 1))
            {
                g[i][j].push_back({{i, j + 1}, p[i][j + 1] + t * 3});
            }
            if (on_grid(i, j - 1))
            {
                g[i][j].push_back({{i, j - 1}, p[i][j - 1] + t * 3});
            }
            for (int k = 0; k < 4; k++)
            {
                if (k == 0 || k == 3)
                {
                    int nx = i + k, ny = j + (3 - k);
                    if (on_grid(nx, ny))
                    {
                        g[i][j].push_back({{nx, ny}, p[nx][ny] + 3 * t});
                    }
                    nx = i - k, ny = j - (3 - k);
                    if (on_grid(nx, ny))
                    {
                        g[i][j].push_back({{nx, ny}, p[nx][ny] + 3 * t});
                    }
                }
                else
                {
                    int nx = i + k, ny = j + (3 - k);
                    if (on_grid(nx, ny))
                    {
                        g[i][j].push_back({{nx, ny}, p[nx][ny] + 3 * t});
                    }
                    nx = i + k, ny = j - (3 - k);
                    if (on_grid(nx, ny))
                    {
                        g[i][j].push_back({{nx, ny}, p[nx][ny] + 3 * t});
                    }
                    nx = i - k, ny = j + (3 - k);
                    if (on_grid(nx, ny))
                    {
                        g[i][j].push_back({{nx, ny}, p[nx][ny] + 3 * t});
                    }
                    nx = i - k, ny = j - (3 - k);
                    if (on_grid(nx, ny))
                    {
                        g[i][j].push_back({{nx, ny}, p[nx][ny] + 3 * t});
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = 10000000000000005;
        }
    }
    d[0][0] = 0;
    q.push({0, {0, 0}});
    while (!q.empty())
    {
        auto a = q.top().second;
        if (!v[a.x][a.y])
        {
            v[a.x][a.y] = true;
            for (auto u : g[a.x][a.y])
            {
                auto b = u.first;
                long long w = u.second;
                if (d[a.x][a.y] + w < d[b.x][b.y])
                {
                    d[b.x][b.y] = d[a.x][a.y] + w;
                    q.push({d[b.x][b.y], b});
                }
            }
        }
        q.pop();
    }
    cout << d[n - 1][n - 1] << endl;
    return 0;
}