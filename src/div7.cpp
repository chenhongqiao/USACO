#include <bits/stdc++.h>
using namespace std;
vector<int> c;
vector<long long> pfx;
map<int, int> mp;
int main()
{
    int n;
    cin >> n;
    c.reserve(n + 5);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    pfx.reserve(n + 5);
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            pfx[i] = pfx[i - 1];
        }
        pfx[i] += c[i];
    }
    for (int i = 0; i < n; i++)
    {
        pfx[i] %= 7;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        mp[pfx[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, i - mp[pfx[i]]);
    }
    cout << ans << endl;
    return 0;
}