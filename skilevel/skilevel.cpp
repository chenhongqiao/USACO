#include <bits/stdc++.h>
using namespace std;
int m, n, t;
int g[505][505];
int num[505][505];
struct root
{
    int f;
    int con, sp;
    int h;
};
struct path
{
    int a, b;
    int e;
};
vector<path> p;
vector<root> rt;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
long long ans = 0;
bool pcomp(path a, path b)
{
    return a.e < b.e;
}
int find(int cur)
{
    if (rt[cur].f != cur)
    {
        rt[cur].f = find(rt[cur].f);
    }
    return rt[cur].f;
}
void add(int a, int b, int ev)
{
    int fa = find(a);
    int fb = find(b);
    if (fa == fb)
    {
        return;
    }
    if (rt[fa].h > rt[fb].h)
    {
        rt[fb].f = fa;
        rt[fa].con += rt[fb].con;
        rt[fa].sp += rt[fb].sp;
        rt[fa].h = max(rt[fa].h, rt[fb].h + 1);
        if (rt[fa].con >= t && rt[fa].sp != 0)
        {
            ans += ((long long)rt[fa].sp) * ev;
            rt[fa].sp = 0;
        }
    }
    else
    {
        rt[fa].f = fb;
        rt[fb].con += rt[fa].con;
        rt[fb].sp += rt[fa].sp;
        rt[fb].h = max(rt[fb].h, rt[fa].h + 1);
        if (rt[fb].con >= t && rt[fb].sp != 0)
        {
            ans += ((long long)rt[fb].sp) * ev;
            rt[fb].sp = 0;
        }
    }
}
int main()
{
    //freopen("skilevel.in", "r", stdin);
    //freopen("skilevel.out", "w", stdout);
    cin >> m >> n >> t;
    if (t == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            num[i][j] = cnt;
            cnt++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int kx = i + dx[k];
                int ky = j + dy[k];
                if (kx >= 0 && kx < m && ky >= 0 && ky < n)
                {
                    p.push_back({num[i][j], num[kx][ky], abs(g[i][j] - g[kx][ky])});
                }
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        rt.push_back({i, 1, 0, 0});
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
            {
                rt[num[i][j]].sp++;
            }
        }
    }
    sort(p.begin(), p.end(), pcomp);
    for (int i = 0; i < p.size(); i++)
    {
        add(p[i].a, p[i].b, p[i].e);
    }
    cout << ans << endl;
    return 0;
}