// Substring
#include <iostream>
const int p = 1000000007;
using namespace std;
int dp[205][2005];
string a, b;
char a_at(int i)
{
    return a[i - 1];
}
char b_at(int i)
{
    return b[i - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    cin >> a >> b;
    dp[0][0] = 1;
    for (int i = 0; i < k; i++)
    {
        int psum[205][2005] = {{0}};
        for (int i = 0; i <= m; i++)
        {
            psum[i][0] = dp[i][0];
            for (int j = 1; j <= n; j++)
            {
                psum[i][j] = dp[i][j] + psum[i][j - 1];
                psum[i][j] %= p;
            }
        }
        for (int j = m; j > 0; j--)
        {
            for (int k = n; k >= j; k--)
            {
                int ofs = 0;
                int ans = 0;
                while (j - ofs > 0 && k - ofs > 0 && a_at(k - ofs) == b_at(j - ofs) && j - ofs > i)
                {
                    ans += psum[j - ofs - 1][k - ofs - 1];
                    ans %= p;
                    ofs++;
                }
                dp[j][k] = ans;
            }
        }
    }
    int ans = 0;
    for (int i = m; i <= n; i++)
    {
        ans += dp[m][i];
        ans %= p;
    }
    cout << ans << "\n";
    return 0;
}