#include <bits/stdc++.h>
using namespace std;
int r[105];
int dp[105][105];
int main()
{
    //freopen("taming.in", "r", stdin);
    //freopen("taming.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[n - i + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 1000000005;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cnt = 0;
            int tmp = 1000000005;
            for (int k = 0; j - k >= 1; k++)
            {
                if (r[j - k] != k)
                {
                    cnt++;
                }
                tmp = min(tmp, cnt + dp[i - 1][j - k - 1]);
            }
            if (i == 1)
            {
                tmp = min(tmp, cnt);
            }
            dp[i][j] = tmp;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i][n] << endl;
    }
    return 0;
}