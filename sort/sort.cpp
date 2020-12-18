#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> a;
vector<pair<int, int>> s;
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
int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        a.push_back({in, i});
    }
    s = a;
    sort(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = i - (lower_bound(s.begin(), s.end(), a[i]) - s.begin());
        ans = max(ans, tmp);
    }
    cout << ans + 1 << endl;
    return 0;
}