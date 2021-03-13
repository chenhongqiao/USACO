#include <bits/stdc++.h>
using namespace std;
int g[305];
int dp[305][305];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 1000000000;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
        dp[i][i] = 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (g[i] == g[j])
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            }
            else
            {
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}