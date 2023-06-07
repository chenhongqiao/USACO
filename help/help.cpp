// Help Yourself
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> s;
int dp[100005];
int mod = 1000000007;
int psum[200005];
long long binpow(long long a, long long b)
{
    a %= mod;
    long long ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s.push_back({a, b});
        psum[b] += 1;
    }
    for (int i = 1; i < 200000; i++)
    {
        psum[i] += psum[i - 1];
    }
    sort(s.begin(), s.end());
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] * 2;
        dp[i] %= mod;
        if (s[i].first - 1 >= 0)
        {
            dp[i] += binpow(2, psum[s[i].first - 1]);
            dp[i] %= mod;
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}