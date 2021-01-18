#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
using namespace std;
int n;
int m[255][255];
int c[255][255];
bool bv[255][255];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct region
{
    int size;
    int om;
    umap<int, uset<int>> adjc;
};
umap<int, region> mp;
void coloring(int x, int y, int color)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    int cnt = 0;
    c[x][y] = color;
    while (!q.empty())
    {
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int kx = q.front().first + dx[i];
            int ky = q.front().second + dy[i];
            if (kx >= 0 && kx < n && ky >= 0 && ky < n && c[kx][ky] == 0 && m[kx][ky] == m[x][y])
            {
                c[kx][ky] = color;
                q.push({kx, ky});
            }
        }
        q.pop();
    }
    mp[color].size = cnt;
    mp[color].om = m[x][y];
}
void build_graph(int x, int y, int color)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    bv[x][y] = true;
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int kx = q.front().first + dx[i];
            int ky = q.front().second + dy[i];
            if (kx >= 0 && kx < n && ky >= 0 && ky < n)
            {
                if (c[kx][ky] == color)
                {
                    if (!bv[kx][ky])
                    {
                        bv[kx][ky] = true;
                        q.push({kx, ky});
                    }
                }
                else
                {
                    mp[color].adjc[m[kx][ky]].insert(c[kx][ky]);
                }
            }
        }
        q.pop();
    }
}
uset<int> cv;
int dfs(int f, int alt)
{
    int cnt = 0;
    for (auto it = mp[f].adjc[alt].begin(); it != mp[f].adjc[alt].end(); it++)
    {
        if (cv.find(*it) == cv.end())
        {
            cv.insert(*it);
            cnt += dfs(*it, mp[f].om);
        }
    }
    return cnt + mp[f].size;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] == 0)
            {
                coloring(i, j, cnt);
                cnt++;
            }
        }
    }
    int ans1 = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans1 = max(ans1, it->second.size);
    }
    cout << ans1 << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!bv[i][j])
            {
                build_graph(i, j, c[i][j]);
            }
        }
    }
    int ans = 0;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        for (auto j = i->second.adjc.begin(); j != i->second.adjc.end(); j++)
        {
            cv.clear();
            cv.insert(i->first);
            ans = max(ans, dfs(i->first, j->first));
        }
    }
    cout << ans << endl;
    return 0;
}