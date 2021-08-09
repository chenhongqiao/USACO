//Book Shop
#include <bits/stdc++.h>
using namespace std;
int h[1005];
int s[1005];
int dp[100005];
int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = x; i >= h[j]; i--)
        {
            dp[i] = max(dp[i], dp[i - h[j]] + s[j]);
        }
    }
    cout << dp[x] << endl;
    return 0;
}