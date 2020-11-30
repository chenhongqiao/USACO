#include <bits/stdc++.h>
using namespace std;
struct cow
{
    int s, a, t;
};
bool a_comp(const cow &a, const cow &b)
{
    return a.a < b.a;
}
struct s_comp
{
    template <typename T>
    bool operator()(const T &a, const T &b) const
    {
        return a.s < b.s;
    }
};
vector<cow> c;
set<cow, s_comp> q;
int main()
{
    //freopen("convention2.in", "r", stdin);
    //freopen("convention2.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, t;
        cin >> a >> t;
        c.push_back({i, a, t});
    }
    sort(c.begin(), c.end(), a_comp);
    int p = 0;
    int t = 0;
    int ans = 0;
    while (p < n)
    {
        if (q.empty())
        {
            q.insert(c[p]);
            t = c[p].a;
            p++;
        }
        ans = max(ans, t - q.begin()->a);
        t += q.begin()->t;
        q.erase(q.begin());
        while (p < n && c[p].a <= t)
        {
            q.insert(c[p]);
            p++;
        }
    }
    cout << ans << endl;
    return 0;
}