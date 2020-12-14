#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
int n;
char g[25][25];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct pcl
{
    int x1, y1, x2, y2;
};
vector<pcl> p;
bool cpcl(int x1, int y1, int x2, int y2)
{
    bool v[25][25] = {false};
    umap<char, int> m;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (!v[i][j])
            {
                char c = g[i][j];
                m[c]++;
                if (m.size() > 2)
                {
                    return false;
                }
                queue<pair<int, int>> q;
                v[i][j] = true;
                q.push({i, j});
                while (!q.empty())
                {
                    int kx = q.front().first;
                    int ky = q.front().second;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = kx + dx[k];
                        int ny = ky + dy[k];
                        if (nx >= x1 && nx <= x2 && ny >= y1 && ny <= y2)
                        {
                            if (!v[nx][ny] && g[nx][ny] == c)
                            {
                                q.push({nx, ny});
                                v[nx][ny] = true;
                            }
                        }
                    }
                    q.pop();
                }
            }
        }
    }
    if (m.size() == 2)
    {
        auto f = m.begin();
        auto s = m.begin();
        s++;
        if ((f->second == 1 && s->second >= 2) || (f->second >= 2 && s->second == 1))
        {
            return true;
        }
    }
    return false;
}
bool check(int x1, int y1, int x2, int y2)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].x1 <= x1 && p[i].y1 <= y1 && p[i].x2 >= x2 && p[i].y2 >= y2)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    //freopen("where.in", "r", stdin);
    //freopen("where.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = n - 1; k >= i; k--)
            {
                for (int l = n - 1; l >= j; l--)
                {
                    if (check(i, j, k, l))
                    {
                        if (cpcl(i, j, k, l))
                        {
                            p.push_back({i, j, k, l});
                            ans++;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}