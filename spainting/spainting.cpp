// Stamp Painting
#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1000000007;
long long binpow(long long a, long long b)
{
    a %= mod;
    long long ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
long long n, m, k;
long long dp[1000005];
long long c = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    dp[0] = m;
    c = m;
    for (int i = 1; i < k - 1; i++)
    {
        dp[i] = dp[i - 1] * m;
        c += dp[i];
        dp[i] %= mod;
        c %= mod;
    }
    for (int i = k - 1; i < n; i++)
    {
        dp[i] = c * (m - 1) % mod;
        c = c - dp[i - k + 1] + dp[i] + mod;
        c %= mod;
    }
    cout << (binpow(m, n) + mod - dp[n - 1]) % mod << endl;
    return 0;
}