//Luogu P2376
#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
vector<pair<int, int>> l;
int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int v, b;
        cin >> v >> b;
        l.push_back({v, b});
    }
    sort(l.begin(), l.end(), comp);
    int ans = 0;
    while (1)
    {
        vector<int> p;
        int tmp = 0;
        int d = 100000000;
        for (int i = 0; i < l.size(); i++)
        {
            int k = min(l[i].second, (c - tmp) / l[i].first);
            p.push_back(k);
            tmp += k * l[i].first;
            if (k != 0)
            {
                d = min(d, l[i].second / k);
            }
        }
        if (tmp < c)
        {
            for (int i = l.size() - 1; i >= 0; i--)
            {
                while (p[i] < l[i].second && tmp < c)
                {
                    p[i]++;
                    tmp += l[i].first;
                }
                if (p[i] != 0)
                {
                    d = min(d, l[i].second / p[i]);
                }
                if (tmp >= c)
                {
                    break;
                }
            }
        }
        if (tmp < c)
        {
            break;
        }
        else
        {
            for (int i = 0; i < l.size(); i++)
            {
                l[i].second -= p[i] * d;
            }
            ans += d;
        }
    }
    cout << ans << endl;
    return 0;
}