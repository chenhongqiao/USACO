#include <bits/stdc++.h>
using namespace std;
vector<int> c;
int dp[1000005];
int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        c.push_back(v);
    }
    sort(c.begin(), c.end());
    for (int i = 1; i < 1000005; i++)
    {
        dp[i] = 1000000005;
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < c.size(); j++)
        {
            if (i - c[j] < 0)
            {
                break;
            }
            dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    if (dp[x] == 1000000005)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }
    return 0;
}