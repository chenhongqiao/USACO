#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<long long, long long>> g;
long long check(long long d)
{
    long long cnt = 0;
    long long l = 0;
    for (int i = 0; i < g.size(); i++)
    {
        long long s = max(g[i].first, l);
        long long tmp = (g[i].second - s + 1 + d) / (d + 1);
        if (tmp > 0)
        {
            cnt += tmp;
            l = s + tmp * (d + 1);
        }
    }
    return cnt;
}
int main()
{
    //freopen("socdist.in", "r", stdin);
    //freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int b, e;
        cin >> b >> e;
        g.push_back({b, e});
    }
    sort(g.begin(), g.end());
    long long h = 0, t = 1000000000000000005;
    while (h < t - 1)
    {
        long long p = h + (t - h + 1) / 2;
        long long tmp = check(p);
        if (tmp < n)
        {
            t = p;
            continue;
        }
        else
        {
            h = p;
            continue;
        }
    }
    cout << t << endl;
    return 0;
}