#include <iostream>
#include <queue>
using namespace std;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    bool s[105][105] = {false};
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        s[a][b] = true;
    }
    bool v[105][105] = {false};
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] && !v[i][j])
            {
                int cnt = 1;
                queue<pair<int, int>> q;
                v[i][j] = true;
                q.push({i, j});
                while (!q.empty())
                {
                    int ci = q.front().first;
                    int cj = q.front().second;
                    if (s[ci + 1][cj] && !v[ci + 1][cj])
                    {
                        q.push({ci + 1, cj});
                        v[ci + 1][cj] = true;
                        cnt++;
                    }
                    if (s[ci - 1][cj] && !v[ci - 1][cj])
                    {
                        q.push({ci - 1, cj});
                        v[ci - 1][cj] = true;
                        cnt++;
                    }
                    if (s[ci][cj + 1] && !v[ci][cj + 1])
                    {
                        q.push({ci, cj + 1});
                        v[ci][cj + 1] = true;
                        cnt++;
                    }
                    if (s[ci][cj - 1] && !v[ci][cj - 1])
                    {
                        q.push({ci, cj - 1});
                        v[ci][cj - 1] = true;
                        cnt++;
                    }
                    q.pop();
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    solve();
}