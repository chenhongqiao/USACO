#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
vector<pair<int, int>> r[105][105];
bool l[105][105];
bool v[105][105];
bool lv[105][105];
queue<pair<int, int>> q;
queue<pair<int, int>> p;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    //freopen("lightson.in", "r", stdin);
    //freopen("lightson.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        r[x][y].push_back({a, b});
    }
    int ans = 1;
    int lu = 0;
    int llu = 0;
    q.push({1, 1});
    l[1][1] = true;
    v[1][1] = true;
    while (1)
    {
        while (!q.empty())
        {
            int tmp = 0;
            for (int i = 0; i < 4; i++)
            {
                int kx = q.front().f + dx[i];
                int ky = q.front().s + dy[i];
                if (kx >= 1 && kx <= n && ky >= 1 && ky <= n)
                {
                    if (!v[kx][ky] && !l[kx][ky])
                    {
                        tmp++;
                    }
                    if (!v[kx][ky] && l[kx][ky])
                    {
                        ans++;
                        v[kx][ky] = true;
                        q.push({kx, ky});
                    }
                }
            }
            if (!lv[q.front().f][q.front().s])
            {
                for (int i = 0; i < r[q.front().f][q.front().s].size(); i++)
                {
                    lu++;
                    l[r[q.front().f][q.front().s][i].f][r[q.front().f][q.front().s][i].s] = true;
                }
                lv[q.front().f][q.front().s] = true;
            }
            if (tmp > 0)
            {
                p.push({q.front().f, q.front().s});
            }
            q.pop();
        }
        if (lu == llu)
        {
            break;
        }
        else
        {
            llu = lu;
            while (!p.empty())
            {
                q.push({p.front().f, p.front().s});
                p.pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}