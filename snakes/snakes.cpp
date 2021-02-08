#include <bits/stdc++.h>
using namespace std;
int s[405];
int dp[405][405];
int main()
{
    //freopen("snakes.in", "r", stdin);
    //freopen("snakes.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < 405; i++)
    {
        for (int j = 0; j < 405; j++)
        {
            dp[i][j] = 1000000000;
        }
    }

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tp = 0;
            int cnt = 0;
            for (int l = 0; j - l >= 0; l++)
            {
                if (s[j - l] <= tp)
                {
                    cnt += (tp - s[j - l]);
                }
                else
                {
                    cnt += (s[j - l] - tp) * l;
                    tp = s[j - l];
                }
                if (i != 0)
                {
                    dp[i][j] = min(dp[i][j], (j - l - 1 >= 0 ? dp[i - 1][j - l - 1] : 0) + cnt);
                }
            }
            if (i == 0)
            {
                dp[i][j] = min(dp[i][j], cnt);
            }
        }
    }
    cout << dp[k][n - 1] << endl;
    return 0;
}