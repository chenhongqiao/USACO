#include <bits/stdc++.h>
using namespace std;
int dp[105][1000005];
int c[105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
        cin >> c[i];
    }
    for (int i = 1; i <= x; i++)
    {
        if (i - c[0] >= 0)
        {
            dp[0][i] += dp[0][i - c[0]];
            dp[0][i] %= 1000000007;
        }
        for (int j = 1; j < n; j++)
        {
            dp[j][i] = dp[j - 1][i];
            if (i - c[j] >= 0)
            {
                dp[j][i] += dp[j][i - c[j]];
                dp[j][i] %= 1000000007;
            }
        }
    }
    cout << dp[n - 1][x] << endl;
    return 0;
}