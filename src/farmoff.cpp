#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> cow;
bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}
int main()
{
    long long n, a, b, c, d, e, f, g, h, m;
    cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m;
    for (int i = 0; i < 3 * n; i++)
    {
        long long i2 = (i % d) * (i % d) % d;
        long long i3 = i2 * (i % d) % d;
        long long i5 = (i2 % d) * (i3 % d) % d;
        long long w = ((a % d) * i5 % d + (b % d) * i2 % d + c % d) % d;
        i2 = (i % h) * (i % h) % h;
        i3 = i2 * (i % h) % h;
        i5 = (i2 % h) * (i3 % h) % h;
        long long u = ((e % h) * i5 % h + (f % h) * i3 % h + g % h) % h;
        cow.push_back({u, w});
    }
    long long ans = 0;
    sort(cow.begin(), cow.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        ans += (cow[i].second % m);
        ans %= m;
    }
    cout << ans % m << endl;
    return 0;
}