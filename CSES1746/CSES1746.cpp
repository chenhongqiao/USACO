//Array Description
#include <bits/stdc++.h>
using namespace std;
int a[100005];
long long dp[100005][105];
const int mod = 1000000007;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
                    dp[i][j] %= mod;
                }
            }
        }
        else
        {
            if (i == 0)
            {
                dp[i][a[i]] = 1;
            }
            else
            {
                dp[i][a[i]] = dp[i - 1][a[i]] + dp[i - 1][a[i] - 1] + dp[i - 1][a[i] + 1];
                dp[i][a[i]] %= mod;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += dp[n - 1][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}