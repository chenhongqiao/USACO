#include <bits/stdc++.h>
using namespace std;
pair<int, int> hc[1005];
pair<int, int> gc[1005];
long long dp[1005][1005][2];
long long dist(pair<int, int> a, pair<int, int> b)
{
    long long one = 1;
    return one * abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second);
}
int main()
{
    int h, g;
    cin >> h >> g;
    for (int i = 1; i <= h; i++)
    {
        int x, y;
        cin >> x >> y;
        hc[i] = {x, y};
    }
    for (int i = 1; i <= g; i++)
    {
        int x, y;
        cin >> x >> y;
        gc[i] = {x, y};
    }
    for (int i = 0; i < 1005; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            dp[i][j][0] = 2000000005;
            dp[i][j][1] = 2000000005;
        }
    }
    dp[1][0][0] = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j <= g; j++)
        {
            long long s1 = dp[i - 1][j][0] + dist(hc[i], hc[i - 1]);
            long long s2 = dp[i - 1][j][1] + dist(hc[i], gc[j]);
            dp[i][j][0] = min(min(dp[i][j][0], s1), s2);
            if (j > 0)
            {
                long long s1 = dp[i][j - 1][0] + dist(gc[j], hc[i]);
                long long s2 = dp[i][j - 1][1] + dist(gc[j], gc[j - 1]);
                dp[i][j][1] = min(min(dp[i][j][1], s1), s2);
            }
        }
    }
    cout << dp[h][g][0] << endl;
    return 0;
}