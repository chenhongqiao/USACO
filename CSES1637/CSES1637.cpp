#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
vector<int> decomp(int v)
{
    vector<int> d;
    while (v > 0)
    {
        d.push_back(v % 10);
        v /= 10;
    }
    return d;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1000000005;
    }
    for (int i = 1; i <= n; i++)
    {
        auto d = decomp(i);
        for (int j = 0; j < d.size(); j++)
        {
            if (i - d[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - d[j]] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}