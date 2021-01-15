#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long check(long long p)
{
    long long l = n;
    long long d = 0;
    while (1)
    {
        long long y = l / p;
        if (y < m)
        {
            break;
        }
        long long tmp = (l - y * p) / y + 1;
        d += tmp;
        l -= y * tmp;
    }
    d += (l + m - 1) / m;
    return d;
}
int main()
{
    //freopen("loan.in", "r", stdin);
    //freopen("loan.out", "w", stdout);
    cin >> n >> k >> m;
    long long h = 1, t = 1000000000000;
    while (h < t - 1)
    {
        long long p = (h + t + 1) / 2;
        long long tmp = check(p);
        if (tmp > k)
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
    cout << h << endl;
    return 0;
}