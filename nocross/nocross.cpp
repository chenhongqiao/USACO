#include <bits/stdc++.h>
using namespace std;
vector<int> l;
vector<int> r;
int dp[1005][1005];
int main()
{
    //freopen("nocross.in", "r", stdin);
    //freopen("nocross.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        l.push_back(c);
    }
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        r.push_back(c);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(l[i] - r[j]) <= 4)
            {
                if (i > 0 && j > 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                else
                {
                    dp[i][j] = max(dp[i][j], 1);
                }
                if (i > 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
                if (j > 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
            else
            {
                if (i > 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
                if (j > 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}