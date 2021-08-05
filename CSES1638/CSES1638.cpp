#include <bits/stdc++.h>
using namespace std;
char g[1005][1005];
int dp[1005][1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    if (g[1][1] == '*' || g[n][n] == '*')
    {
        cout << 0 << endl;
        return 0;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i != 1 || j != 1) && g[i][j] != '*')
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= 1000000007;
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}