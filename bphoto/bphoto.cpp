#include <bits/stdc++.h>
using namespace std;
int n;
int m = 1;
vector<pair<int, int>> h;
int tree[2][100005];
bool scomp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
void update(int p, int v, int o)
{
    while (p <= m)
    {
        tree[o][p] += v;
        p += p & -p;
    }
}
int sum(int p, int o)
{
    int s = 0;
    while (p > 0)
    {
        s += tree[o][p];
        p -= p & -p;
    }
    return s;
}
int main()
{
    //freopen("bphoto.in", "r", stdin);
    //freopen("bphoto.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        h.push_back({v, i});
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            if (h[i].first != h[i - 1].first)
            {
                m++;
            }
        }
        h[i].first = m;
    }
    sort(h.begin(), h.end(), scomp);
    for (int i = 0; i < n; i++)
    {
        update(h[i].first, 1, 0);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        update(h[i].first, 1, 1);
        int l = sum(m, 1) - sum(h[i].first, 1);
        int r = sum(m, 0) - sum(h[i].first, 0) - l;
        if (min(l, r) * 2 < max(l, r))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}