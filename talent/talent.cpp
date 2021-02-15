#include <bits/stdc++.h>
using namespace std;
struct cow
{
    long long w, t;
};
cow c[255];
long long dp[1000005];
int main()
{
    //freopen("talent.in", "r", stdin);
    //freopen("talent.out", "w", stdout);
    int n, wl;
    cin >> n >> wl;
    for (int i = 1; i <= n; i++)
    {
        long long w, t;
        cin >> w >> t;
        c[i] = {w, t * 1000};
    }
    for (int i = 1; i <= 1000000; i++)
    {
        dp[i] = -10000000000;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1000000; j >= c[i].w; j--)
        {
            dp[j] = max(dp[j], dp[j - c[i].w] + c[i].t);
        }
    }
    int ans = 0;
    for (int i = wl; i <= 1000000; i++)
    {
        if (dp[i] / i > ans)
        {
            ans = dp[i] / i;
        }
    }
    cout << ans << endl;
    return 0;
}