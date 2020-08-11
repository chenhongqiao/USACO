#include <bits/stdc++.h>
using namespace std;
vector<pair<int, char>> c;
vector<pair<int, int>> pfx;
//pfx.first=H Prefix Sum
//pfx.second=G Prefix Sum
map<int, int> mp;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmpx;
        char tmpb;
        cin >> tmpx >> tmpb;
        c.push_back({tmpx - 1, tmpb});
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pfx.push_back({0, 0});
        }
        else
        {
            pfx.push_back({pfx[i - 1].first, pfx[i - 1].second});
        }
        if (c[i].second == 'H')
        {
            pfx[i].first++;
        }
        else if (c[i].second == 'G')
        {
            pfx[i].second++;
        }
    }

    for (int i = n; i >= 0; i--)
    {
        mp[pfx[i].first - pfx[i].second] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(pfx[i].first - pfx[i].second) == mp.end())
        {
            continue;
        }
        if (mp[pfx[i].first - pfx[i].second] == i)
        {
            continue;
        }
        if (pfx[i].first == pfx[i].second)
        {
            ans = max(ans, c[i].first);
        }
        int w = c[i].first - c[mp[pfx[i].first - pfx[i].second] + 1].first;
        ans = max(ans, w);
    }
    int s = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i].second == 'H')
        {
            e = c[i].first;
            ans = max(ans, e - s);
        }
        else
        {
            s = c[i + 1].first;
        }
    }
    s = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i].second == 'G')
        {
            e = c[i].first;
            ans = max(ans, e - s);
        }
        else
        {
            s = c[i + 1].first;
        }
    }
    cout << ans << endl;
    return 0;
}