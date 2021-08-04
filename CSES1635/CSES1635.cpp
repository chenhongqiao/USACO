#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long dp[1000005];
vector<int> c;
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
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < c.size(); j++)
        {
            if (i - c[j] < 0)
            {
                break;
            }
            dp[i] += dp[i - c[j]];
            dp[i] %= mod;
        }
    }
    cout << dp[x] << endl;
    return 0;
}