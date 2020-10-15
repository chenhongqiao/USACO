#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> r; // first: position  second: tastiness
bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}
int main()
{
    int l, n, f, b;
    cin >> l >> n >> f >> b;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        r.push_back({x, c});
    }
    sort(r.begin(), r.end(), comp);
    int lp = 0;
    long long ans = 0;
    long long li = 1;
    for (int i = 0; i < n; i++)
    {
        if (r[i].first > lp)
        {
            ans += (li * r[i].first - lp) * (f - b) * r[i].second;
            lp = r[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}