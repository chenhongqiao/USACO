// Make N

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if ((ll)a.first * b.second == (ll)a.second * b.first)
    {
        return a.first < b.first;
    }
    return (ll)a.first * b.second > (ll)a.second * b.first;
}
ll solve(int n, vector<pair<int, int>> &p)
{
    sort(p.begin(), p.end(), cmp);
    if (p[0].first == 1)
    {
        return (ll)n * p[0].second;
    }
    else if (p[1].first == 1)
    {
        return (ll)(n / p[0].first) * p[0].second + (ll)(n % p[0].first) * p[1].second;
    }
    else
    {
        ll ans = 9000000000000000001;
        if (n / p[0].first < p[0].first - 1)
        {
            for (int i = 0; i <= n / p[0].first && i * p[0].first <= n; i++)
            {
                ll lft = n - i * p[0].first;
                ans = min(ans, (ll)i * p[0].second + (ll)(lft / p[1].first) * p[1].second + (ll)(lft % p[1].first) * p[2].second);
            }
        }
        else
        {
            for (int i = 0; i <= p[0].first - 1 && i * p[1].first <= n; i++)
            {
                ll lft = n - i * p[1].first;
                ans = min(ans, (ll)i * p[1].second + (ll)(lft / p[0].first) * p[0].second + (ll)(lft % p[0].first) * p[2].second);
            }
        }
        return ans;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<pair<int, int>> p(3);
        p[2].first = 1;
        cin >> n >> p[0].first >> p[1].first >> p[2].second >> p[0].second >> p[1].second;
        cout << solve(n, p) << "\n";
    }
    return 0;
}