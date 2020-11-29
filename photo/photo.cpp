#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> c;
bool v[1005];
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int b, e;
        cin >> b >> e;
        if (b < e)
        {
            c.push_back({b, e});
        }
        else
        {
            c.push_back({e, b});
        }
    }
    sort(c.begin(), c.end(), comp);

    int ans = 0;
    int l = 0;
    for (int i = 0; i < k; i++)
    {
        if (c[i].first > l)
        {
            l = c[i].second;
            ans++;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}