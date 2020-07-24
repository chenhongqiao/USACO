#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> r;
vector<pair<int, int>> l;
vector<pair<int, int>> a;
bool ucmp(int a, pair<int, int> b)
{
    return a < b.first;
}
int main()
{
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    int n, e;
    int aw = 0;
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        int w, x, d;
        cin >> w >> x >> d;
        aw += w;
        if (d == 1)
        {
            r.push_back({x, w});
        }
        else
        {
            l.push_back({x, w});
        }
    }
    sort(r.begin(), r.end());
    sort(l.begin(), l.end());
    for (int i = r.size() - 1; i >= 0; i--)
    {
        int fn = upper_bound(l.begin(), l.end(), r.at(i).first, ucmp) - l.begin();
        for (int j = fn; j < l.size(); j++)
        {
            int mt = (l.at(j).first - r.at(i).first + 1) / 2;
            int tmp = l.at(j).second;
            l.at(j).second = r.at(i).second;
            r.at(i).second = tmp;
        }
        int at = e - r.at(i).first;
        a.push_back({at, r.at(i).second});
    }
    for (int i = 0; i < l.size(); i++)
    {
        int at = l.at(i).first;
        a.push_back({at, l.at(i).second});
    }
    sort(a.begin(), a.end());
    int nw = 0;
    int t;
    for (int i = 0; i < a.size(); i++)
    {
        nw += a.at(i).second;
        if (nw >= (aw + 1) / 2)
        {
            t = a.at(i).first;
            break;
        }
    }
    int ans = 0;
    for (int i = r.size() - 1; i >= 0; i--)
    {
        int fn = upper_bound(l.begin(), l.end(), r.at(i).first, ucmp) - l.begin();
        for (int j = fn; j < l.size(); j++)
        {
            int mt = (l.at(j).first - r.at(i).first + 1) / 2;
            if (mt <= t)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}