//Cow Poetry
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> rc;
vector<int> wl;
unordered_map<char, int> rg;
unordered_map<char, long long> ansg;
long long dp[5005];
unordered_map<int, long long> dpc;
const int mod = 1000000007;
long long binpow(long long a, long long b)
{
    a %= mod;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int s, c;
        cin >> s >> c;
        wl.push_back(s);
        rc[c].push_back(s);
    }
    for (int i = 0; i < m; i++)
    {
        char e;
        cin >> e;
        rg[e]++;
    }
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < wl.size(); j++)
        {
            if (i - wl[j] >= 0)
            {
                dp[i] += dp[i - wl[j]];
                dp[i] %= mod;
            }
        }
    }
    for (auto i = rc.begin(); i != rc.end(); i++)
    {
        auto v = i->second;
        int c = i->first;
        for (int j = 0; j < v.size(); j++)
        {
            dpc[c] += dp[k - v[j]];
            dpc[c] %= mod;
        }
    }
    for (auto i = rg.begin(); i != rg.end(); i++)
    {
        char g = i->first;
        int sz = i->second;
        for (auto j = dpc.begin(); j != dpc.end(); j++)
        {
            ansg[g] += binpow(j->second, sz);
            ansg[g] %= mod;
        }
    }
    long long ans = 1;
    for (auto i = ansg.begin(); i != ansg.end(); i++)
    {
        ans *= i->second;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}