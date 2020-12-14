#include <bits/stdc++.h>
using namespace std;
vector<int> cow;
vector<pair<int, int>> bm;
vector<int> rt;
bool pcomp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}
bool rcomp(const int &a, const int &b)
{
    return a > b;
}
int main()
{
    //freopen("rental.in", "r", stdin);
    //freopen("rental.out", "w", stdout);
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        cow.push_back(in);
    }
    for (int i = 0; i < m; i++)
    {
        int q, p;
        cin >> q >> p;
        bm.push_back({q, p});
    }
    for (int i = 0; i < r; i++)
    {
        int in;
        cin >> in;
        rt.push_back(in);
    }
    sort(cow.begin(), cow.end(), rcomp);
    sort(bm.begin(), bm.end(), pcomp);
    sort(rt.begin(), rt.end(), rcomp);
    int h = 0;
    bool sell = false;
    long long ans = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        long long tmp = 0;
        if (!sell)
        {
            while (cow[i] > 0)
            {
                int g = min(cow[i], bm[h].first);
                cow[i] -= g;
                bm[h].first -= g;
                tmp += bm[h].second * g;
                if (bm[h].first == 0)
                {
                    h++;
                }
                if (h >= m)
                {
                    sell = true;
                    break;
                }
            }
        }
        if (n - 1 - i < r && tmp < rt[n - 1 - i])
        {
            ans += rt[n - 1 - i];
            sell = true;
        }
        else
        {
            ans += tmp;
        }
    }
    cout << ans << endl;
    return 0;
}