#include <bits/stdc++.h>
using namespace std;
vector<pair<int, bool>> c;
bool cmp(const pair<int, bool> &b, const int &a)
{
    return a > b.first;
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        string s;
        int w;
        cin >> s >> w;
        if (s == "S")
        {
            c.push_back({w, true});
        }
        else
        {
            c.push_back({w, false});
        }
    }
    sort(c.begin(), c.end());
    int ans = 0;
    int sp = lower_bound(c.begin(), c.end(), a, cmp) - c.begin();
    if (c[sp].first > a)
    {
        sp--;
    }
    if (sp == -1)
    {
        if (c[0].second)
        {
            ans += c[0].first - a;
        }
        sp = 0;
    }
    int lp = lower_bound(c.begin(), c.end(), b, cmp) - c.begin();
    if (lp == -1)
    {
        if (c[n - 1].second)
        {
            ans += b - c[n - 1].first + 1;
        }
        lp = n - 1;
    }
    for (int i = sp; i < lp; i++)
    {
        int k = c[i + 1].first - c[i].first;
        int ls = (c[i].first > a ? c[i].first : a);
        int le = (c[i].first + k / 2 < b ? c[i].first + k / 2 : b);
        if (k % 2 == 0 && le == c[i].first + k / 2)
        {
            le--;
        }
        int rs = c[i].first + k / 2 + 1 > a ? c[i].first + k / 2 + 1 : a;
        int re = (c[i + 1].first - 1 < b ? c[i + 1].first - 1 : b);
        if (c[i].second)
        {
            if (le - ls + 1 > 0)
            {
                ans += (le - ls + 1);
            }
        }
        if (c[i + 1].second)
        {
            if (re - rs + 1 > 0)
            {
                ans += (re - rs + 1);
            }
        }
        if (k % 2 == 0)
        {
            if (c[i].first + k / 2 >= a && c[i].first + k / 2 <= b)
            {
                if (c[i].second || c[i + 1].second)
                {
                    ans++;
                }
            }
        }
    }
    if (c[lp].first == b && c[lp].second)
    {
        ans++;
    }
    cout << ans << endl;
    return 0;
}