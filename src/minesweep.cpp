#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int g[35][35];
int d[3] = {0, 1, -1};
vector<pair<int, int>> p;
pair<int, int> ans[1005];
int ansh;
int dfs(int dep)
{
    if (dep >= p.size() || ansh >= k)
    {
        bool is_ans = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] != 0)
                {
                    is_ans = false;
                    break;
                }
            }
        }
        if (is_ans)
        {
            for (int i = 0; i < ansh; i++)
            {
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
            }
            exit(0);
        }
        return 0;
    }
    if (p[dep].first - 1 >= 0 && p[dep].first - 1 < n && p[dep].second - 2 >= 0 && p[dep].second - 2 < n && g[p[dep].first - 1][p[dep].second - 2] > 0)
    {
        return -1;
    }
    if (p[dep].second - 2 >= 0 && p[dep].second - 2 < n && g[p[dep].first][p[dep].second - 2] > 3)
    {
        return -1;
    }
    bool is_legi = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (p[dep].first + d[i] >= 0 && p[dep].first + d[i] < n && p[dep].second + d[j] >= 0 && p[dep].second + d[j] < m)
            {
                g[p[dep].first + d[i]][p[dep].second + d[j]] -= 1;
                if (g[p[dep].first + d[i]][p[dep].second + d[j]] < 0)
                {
                    is_legi = false;
                }
            }
        }
    }
    int tmp = 0;
    if (is_legi)
    {
        ans[ansh] = {p[dep].first, p[dep].second};
        ansh++;
        tmp = dfs(dep + 1);
        ansh--;
        ans[ansh] = {0, 0};
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (p[dep].first + d[i] >= 0 && p[dep].first + d[i] < n && p[dep].second + d[j] >= 0 && p[dep].second + d[j] < m)
            {
                g[p[dep].first + d[i]][p[dep].second + d[j]] += 1;
            }
        }
    }
    if (tmp != -1)
    {
        dfs(dep + 1);
    }
    return tmp;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            p.push_back({i, j});
        }
    }
    dfs(0);
    cout << "NO SOLUTION" << endl;
    return 0;
}