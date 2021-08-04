#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long dp[1000005];
int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 && i - j >= 0; j++)
        {
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}