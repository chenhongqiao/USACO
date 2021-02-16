#include <bits/stdc++.h>
using namespace std;
long long r[1005];
int main()
{
    //freopen("cbarn2.in", "r", stdin);
    //freopen("cbarn2.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[n - i + 1];
    }
    long long ans = 100000000000;
    for (int i = 0; i < n; i++)
    {
        long long dp[10][105];
        long long cp[1005];
        for (int j = 0; j < 105; j++)
        {
            for (int l = 0; l < 10; l++)
            {
                dp[l][j] = 100000000000;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if ((j + i) / (n + 1) > 0)
            {
                cp[(j + i) % (n + 1) + 1] = r[j];
            }
            else
            {
                cp[(j + i)] = r[j];
            }
        }
        for (int j = 1; j <= k; j++)
        {
            for (int l = 1; l <= n; l++)
            {
                long long tmp = 1000000000;
                long long cnt = 0;
                for (int m = 1; l - m >= 0; m++)
                {
                    tmp = min(tmp, cnt + dp[j - 1][l - m]);
                    cnt += cp[l - m] * m;
                }
                tmp = min(tmp, cnt);
                dp[j][l] = tmp;
            }
        }
        ans = min(ans, dp[k][n]);
    }
    cout << ans << endl;
    return 0;
}