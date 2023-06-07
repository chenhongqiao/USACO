// Snow Boots
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, b;
vector<pair<int, int>> t;
multiset<int> s;
set<int> g;
struct boot
{
    int s, d, id;
};
vector<boot> bt;
bool ans[100005];
bool bt_comp(boot &a, boot &b)
{
    if (a.s == b.s)
    {
        return a.d < b.d;
    }
    return a.s < b.s;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        t.push_back({s, i});
    }
    for (int i = 0; i < b; i++)
    {
        int s, d;
        cin >> s >> d;
        bt.push_back({s, d, i});
    }
    sort(t.begin(), t.end());
    sort(bt.begin(), bt.end(), bt_comp);
    g.insert(0);
    g.insert(n - 1);
    s.insert(n - 1);
    int h = 0;
    for (int i = 0; i < bt.size(); i++)
    {
        while (t[h].first <= bt[i].s && h < n)
        {
            if (g.find(t[h].second) == g.end())
            {
                auto ind = g.upper_bound(t[h].second);
                int st = *prev(ind);
                int ed = *ind;
                s.erase(s.find(ed - st));
                s.insert(ed - t[h].second);
                s.insert(t[h].second - st);
                g.insert(t[h].second);
            }
            h++;
        }
        if (*s.rbegin() <= bt[i].d)
        {
            ans[bt[i].id] = true;
        }
    }
    for (int i = 0; i < b; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}