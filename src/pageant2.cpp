#include <iostream>
#include <queue>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    char p[55][55];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> p[i][j];
        }
    }
    vector<pair<int, int>> l[2];
    bool v[55][55] = {false};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (p[i][j] == 'X' && !v[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                v[i][j] = true;
                while (!q.empty())
                {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    bool edge = false;
                    for (int k = 0; k < 4; k++)
                    {

                        if (!v[cx + dx[k]][cy + dy[k]])
                        {
                            if (p[cx + dx[k]][cy + dy[k]] == 'X')
                            {
                                q.push({cx + dx[k], cy + dy[k]});
                                v[cx + dx[k]][cy + dy[k]] = true;
                            }
                            else
                            {
                                edge = true;
                            }
                        }
                    }
                    if (edge)
                    {
                        l[s].push_back({cx, cy});
                    }
                    q.pop();
                }
                s++;
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
}
int main()
{
    solve();
}