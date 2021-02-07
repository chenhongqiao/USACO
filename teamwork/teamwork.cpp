#include <bits/stdc++.h>
using namespace std;
int c[10005];
int dp[10005];
int main()
{
    //freopen("teamwork.in", "r", stdin);
    //freopen("teamwork.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        int tp = 0;
        for (int j = 0; j < k && i - j >= 0; j++)
        {
            tp = max(tp, c[i - j]);
            tmp = max(tmp, (i - j - 1 >= 0 ? dp[i - j - 1] : 0) + tp * (j + 1));
        }
        dp[i] = tmp;
    }
    cout << dp[n - 1] << endl;
    return 0;
}