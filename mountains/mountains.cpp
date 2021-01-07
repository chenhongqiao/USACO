#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> m;
int height(int f, int h, int k)
{
    int p = f + h;
    if (k > p)
    {
        return p + h - k;
    }
    else
    {
        return k - f;
    }
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
int main()
{
    //freopen("mountains.in", "r", stdin);
    //freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        m.push_back({x - y, y});
    }
    sort(m.begin(), m.end(), cmp);
    int ans = 1;
    int t = m[0].second;
    int f = m[0].first;
    for (int i = 1; i < n; i++)
    {
        if (m[i].second > height(f, t, m[i].first + m[i].second))
        {
            t = m[i].second;
            f = m[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}