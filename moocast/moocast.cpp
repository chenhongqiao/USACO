#include <bits/stdc++.h>
using namespace std;
vector<int> cn[205];
struct cow
{
    int x, y;
    int p;
};
vector<cow> cw;
int n;
int dis(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
}
int bfs(int m)
{
    bool v[205] = {false};
    queue<int> q;
    q.push(m);
    v[m] = true;
    int ans = 1;
    while (!q.empty())
    {
        int km = q.front();
        for (int i = 0; i < cn[km].size(); i++)
        {
            if (!v[cn[km][i]])
            {
                ans++;
                q.push(cn[km][i]);
                v[cn[km][i]] = true;
            }
        }
        q.pop();
    }
    return ans;
}
int main()
{
    //freopen("moocast.in", "r", stdin);
    //freopen("moocast.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, p;
        cin >> x >> y >> p;
        cw.push_back({x, y, p});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (dis(cw[i].x, cw[i].y, cw[j].x, cw[j].y) <= cw[i].p * cw[i].p)
            {
                cn[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, bfs(i));
    }
    cout << ans << endl;
    return 0;
}