// Calculated Coefficients
#include <iostream>
#define ll long long
using namespace std;
ll ia[1005];
ll ib[1005];
const int p = 10007;
void calc_inv(int k)
{
    ia[0] = ia[1] = ib[0] = ib[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        ib[i] = ib[i - 1] * i % p;
        ia[i] = (p - p / i) * ia[p % i] % p;
    }
    for (int i = 2; i <= k; i++)
    {
        ia[i] = ia[i - 1] * ia[i] % p;
    }
}
ll lucas(int x, int y)
{
    if (x < y)
    {
        return 0;
    }
    if (x < p)
    {
        return ib[x] * ia[y] * ia[x - y] % p;
    }
    return lucas(x / p, y / p) * lucas(x % p, y % p) % p;
}
ll binpow(int a, int b)
{
    ll ans = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        a = (ll)a * a % p;
    }
    return ans % p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    calc_inv(k);
    cout << binpow(a, n) * binpow(b, m) * lucas(k, n) % p << "\n";
    return 0;
}