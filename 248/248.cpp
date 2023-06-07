// 248
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n;
int dp[250][250];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = v[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j + i < n; j++)
        {
            int h = j, t = j + i;
            for (int k = h; k < t; k++)
            {
                if (dp[h][k] != 0 && dp[k + 1][t] != 0 && dp[h][k] == dp[k + 1][t])
                {
                    dp[h][t] = max(dp[h][t], dp[h][k] + 1);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}