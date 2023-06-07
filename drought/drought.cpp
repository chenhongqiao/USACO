#include <iostream>
#include <vector>
using namespace std;
int n;
int m = 100000005;
vector<int> h;
const long long mod = 1000000007;
long long ans = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        h.push_back(in);
        m = min(m, in);
    }
    if (n % 2 == 0)
    {
        m = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        vector<int> kh;
        for (int j = 0; j < n; j++)
        {
            kh.push_back(h[j] - i);
        }
        kh.push_back(0);
        long long dp[105][1005] = {{0}};
        long long psum[105][1005] = {{0}};
        for (int j = 0; j <= kh[0]; j++)
        {
            dp[0][j] = 1;
        }
        psum[0][0] = dp[0][0];
        for (int j = 1; j <= 1000; j++)
        {
            psum[0][j] = psum[0][j - 1];
            psum[0][j] += dp[0][j];
            psum[0][j] %= mod;
        }
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k <= kh[j]; k++)
            {
                dp[j][k] += psum[j - 1][kh[j] - k];
                dp[j][k] %= mod;
            }
            psum[j][0] = dp[j][0];
            for (int k = 1; k <= 1000; k++)
            {
                psum[j][k] = psum[j][k - 1];
                psum[j][k] += dp[j][k];
                psum[j][k] %= mod;
            }
        }
        ans += dp[n - 1][0];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}