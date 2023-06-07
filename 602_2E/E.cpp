// Swapping Problem
// #define RAND_TEST

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <cstdlib>
#include <ctime>
typedef long long ll;
const int K = 1000000001;
ll solve(vector<pair<int, int>> &arr)
{
    ll cnt = 0;
    vector<pair<int, int>> cand;
    vector<pair<int, int>> ca;
    vector<pair<int, int>> da;
    for (auto [a, b] : arr)
    {
        cnt += abs(a - b);
        if (a > b)
        {
            cand.push_back({a, b});
        }
        else
        {
            ca.push_back({b, a});
            da.push_back({a, b});
        }
    }

    int ts = ca.size();

    sort(ca.begin(), ca.end());
    sort(da.begin(), da.end());
    int csmin[ca.size()];
    int dpmax[da.size()];

    for (int i = ts - 1; i >= 0; i--)
    {
        if (i == ts - 1)
        {
            csmin[i] = ca[i].second;
        }
        else
        {
            csmin[i] = min(ca[i].second, csmin[i + 1]);
        }
    }

    for (int i = 0; i < ts; i++)
    {
        if (i == 0)
        {
            dpmax[i] = da[i].second;
        }
        else
        {
            dpmax[i] = max(da[i].second, dpmax[i - 1]);
        }
    }

    ll ans = 0;
    for (auto [a, b] : cand)
    {
        auto ld = lower_bound(ca.begin(), ca.end(), make_pair(a, -1));
        if (ld != ca.end())
        {
            ans = max(ans, 2 * (a - (ll)max(b, csmin[ld - ca.begin()])));
        }
        auto hc = upper_bound(da.begin(), da.end(), make_pair(b, K));
        if (hc != da.begin())
        {
            ans = max(ans, 2 * ((ll)min(a, dpmax[prev(hc) - da.begin()]) - b));
        }
    }

    return cnt - ans;
}
ll brute(vector<pair<int, int>> &arr)
{
    ll cnt = 0;
    for (auto [a, b] : arr)
    {
        cnt += abs(a - b);
    }
    ll ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            ll od = abs(arr[i].first - arr[i].second) + abs(arr[j].first - arr[j].second);
            ll nw = abs(arr[i].first - arr[j].second) + abs(arr[j].first - arr[i].second);
            ans = max(ans, od - nw);
        }
    }
    return cnt - ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);

#ifndef RAND_TEST
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].second;
    }
    ll ans = solve(arr);
    for (auto &[a, b] : arr)
    {
        swap(a, b);
    }
    ans = min(ans, solve(arr));
    cout << ans << "\n";
#endif

#ifdef RAND_TEST
    int it = 1000;
    while (it--)
    {
        for (auto &[a, b] : arr)
        {
            a = rand() % 1000000000 + 1;
            b = rand() % 1000000000 + 1;
        }
        ll brt = brute(arr);
        ll slv = solve(arr);
        for (auto &[a, b] : arr)
        {
            swap(a, b);
        }
        slv = min(slv, solve(arr));
        if (brt != slv)
        {
            cout << "Brute: "
                 << brt
                 << "\n"
                 << "Solve: "
                 << slv
                 << "\n";
        }
    }
#endif

    return 0;
}