//Exercise Gold
#include <bits/stdc++.h>
using namespace std;
bool check_prime(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}
vector<int> p;
long long dp[10005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        if (check_prime(i))
        {
            p.push_back(i);
        }
    }
    dp[0] = 1;
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = n; j >= p[i]; j--)
        {
            for (long long k = p[i]; j - k >= 0; k *= p[i])
            {
                dp[j] += (dp[j - k] * k) % m;
                dp[j] %= m;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += dp[i];
        ans %= m;
    }
    cout << ans << endl;
    return 0;
}