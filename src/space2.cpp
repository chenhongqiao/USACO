#include <iostream>
#include <queue>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    char m[1005][1005];
    bool v[1005][1005];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (m[i][j] == '*' && !v[i][j])
            {
                cnt++;
                queue<pair<int, int>> q;
                v[i][j] = true;
                q.push({i, j});
                while (!q.empty())
                {
                    int ci = q.front().first;
                    int cj = q.front().second;
                    if (m[ci + 1][cj] == '*' && !v[ci + 1][cj])
                    {
                        q.push({ci + 1, cj});
                        v[ci + 1][cj] = true;
                    }
                    if (m[ci - 1][cj] == '*' && !v[ci - 1][cj])
                    {
                        q.push({ci - 1, cj});
                        v[ci - 1][cj] = true;
                    }
                    if (m[ci][cj + 1] == '*' && !v[ci][cj + 1])
                    {
                        q.push({ci, cj + 1});
                        v[ci][cj + 1] = true;
                    }
                    if (m[ci][cj - 1] == '*' && !v[ci][cj - 1])
                    {
                        q.push({ci, cj - 1});
                        v[ci][cj - 1] = true;
                    }
                    q.pop();
                }
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    solve();
}