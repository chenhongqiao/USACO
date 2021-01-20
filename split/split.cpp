#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll, ll>> h;
vector<pair<ll, ll>> v;
pair<ll, ll> ht[50005];
pair<ll, ll> htr[50005];
pair<ll, ll> vt[50005];
pair<ll, ll> vtr[50005];
ll enclose1()
{
    ll tx = -1000000005;
    ll ty = -1000000005;
    ll bx = 1000000005;
    ll by = 1000000005;
    for (int i = 0; i < h.size(); i++)
    {
        tx = max(tx, h[i].first);
        ty = max(ty, h[i].second);
        bx = min(bx, h[i].first);
        by = min(by, h[i].second);
    }
    return (tx - bx) * (ty - by);
}
int main()
{
    //freopen("split.in", "r", stdin);
    //freopen("split.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        h.push_back({x, y});
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());

    ll sbest = enclose1();
    for (int i = 0; i < h.size(); i++)
    {
        if (i == 0)
        {
            ht[i] = {h[i].second, h[i].second};
        }
        else
        {
            ll t = max(ht[i - 1].first, h[i].second);
            ll b = min(ht[i - 1].second, h[i].second);
            ht[i] = {t, b};
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
        {
            vt[i] = {v[i].second, v[i].second};
        }
        else
        {
            ll t = max(vt[i - 1].first, v[i].second);
            ll b = min(vt[i - 1].second, v[i].second);
            vt[i] = {t, b};
        }
    }
    for (int i = h.size() - 1; i >= 0; i--)
    {
        if (i == h.size() - 1)
        {
            htr[i] = {h[i].second, h[i].second};
        }
        else
        {
            ll t = max(htr[i + 1].first, h[i].second);
            ll b = min(htr[i + 1].second, h[i].second);
            htr[i] = {t, b};
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (i == v.size() - 1)
        {
            vtr[i] = {v[i].second, v[i].second};
        }
        else
        {
            ll t = max(vtr[i + 1].first, v[i].second);
            ll b = min(vtr[i + 1].second, v[i].second);
            vtr[i] = {t, b};
        }
    }
    ll dbest = 9000000000000000000;
    for (int i = 0; i < h.size() - 1; i++)
    {
        ll tmp = 0;
        tmp += (h[i].first - h[0].first) * (ht[i].first - ht[i].second);
        tmp += (h[n - 1].first - h[i + 1].first) * (htr[i + 1].first - htr[i + 1].second);
        dbest = min(dbest, tmp);
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        ll tmp = 0;
        tmp += (v[i].first - v[0].first) * (vt[i].first - vt[i].second);
        tmp += (v[n - 1].first - v[i + 1].first) * (vtr[i + 1].first - vtr[i + 1].second);
        dbest = min(dbest, tmp);
    }
    cout << sbest - dbest << endl;
    return 0;
}