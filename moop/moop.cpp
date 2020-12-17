#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> p;
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}
int miny[100005];
int maxy[100005];
int main()
{
    //freopen("moop.in", "r", stdin);
    //freopen("moop.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    sort(p.begin(), p.end(), comp);
    miny[0] = p[0].second;
    for (int i = 1; i < n; i++)
    {
        miny[i] = min(miny[i - 1], p[i].second);
    }
    maxy[n - 1] = p[n - 1].second;
    for (int i = n - 2; i >= 0; i--)
    {
        maxy[i] = max(maxy[i + 1], p[i].second);
    }

    int ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (miny[i] > maxy[i + 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}