#include <bits/stdc++.h>
using namespace std;
int f[100005];
int s[100005];
int n;
long long m;
long long ans = 10000000005;
bool check(int p)
{
    long long sum = 0;
    long long cnt = 10000000005;
    multiset<long long> w;
    for (int i = 0; i < p && i < n; i++)
    {
        w.insert(s[i]);
        sum += f[i];
    }
    if (sum >= m)
    {
        cnt = min(cnt, *w.rbegin());
    }
    for (int i = p; i < n; i++)
    {
        w.erase(w.lower_bound(s[i - p]));
        sum -= f[i - p];
        w.insert(s[i]);
        sum += f[i];
        if (sum >= m)
        {
            cnt = min(cnt, *w.rbegin());
        }
    }
    if (cnt == 10000000005)
    {
        return false;
    }
    else
    {
        ans = min(ans, cnt);
        return true;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i] >> s[i];
    }

    int h = 1, t = n;
    while (h + 1 < t)
    {
        int p = (h + t + 1) / 2;
        if (check(p))
        {
            t = p;
        }
        else
        {
            h = p;
        }
    }
    cout << ans << endl;
    return 0;
}