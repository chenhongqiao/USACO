#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int main()
{
    //freopen("pairup.in", "r", stdin);
    //freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());
    int h = 0, t = v.size() - 1;
    int ans = 0;
    while (h <= t)
    {
        int tmp = min(v[h].second, v[t].second);
        v[h].second -= tmp;
        v[t].second -= tmp;
        ans = max(ans, v[h].first + v[t].first);
        if (v[h].second <= 0)
        {
            h++;
        }
        if (v[t].second <= 0)
        {
            t--;
        }
    }
    cout << ans << endl;
    return 0;
}