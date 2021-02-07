#include <bits/stdc++.h>
using namespace std;
int m[100005];
int psum[100005][4];
int dp[100005][25][5];
int n, k;
int main()
{
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        char fg;
        cin >> fg;
        switch (fg)
        {
        case 'H':
            m[i] = 1;
            break;
        case 'P':
            m[i] = 2;
            break;
        case 'S':
            m[i] = 3;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                int tmp = 0;
                for (int l = 1; l <= 3; l++)
                {
                    if (k == l)
                    {
                        tmp = max(tmp, dp[i - 1][j][k] + (m[i] == k));
                    }
                    else if (j > 0)
                    {
                        tmp = max(tmp, dp[i - 1][j - 1][l] + (m[i] == k));
                    }
                }
                dp[i][j][k] = tmp;
            }
        }
    }
    cout << max(dp[n][k][1], max(dp[n][k][2], dp[n][k][3])) << endl;
    return 0;
}