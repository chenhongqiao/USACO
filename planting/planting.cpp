#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
int n;
umap<int, vector<pair<int, int>>> s;
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y2; j < y1; j++)
        {
            s[j].push_back({x1, 1});
            s[j].push_back({x2, -1});
        }
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        sort(it->second.begin(), it->second.end(), comp);
    }
    int ans = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        auto v = it->second;
        int cnt = 0;
        int l = -1;
        for (int i = 0; i < v.size(); i++)
        {
            cnt += v[i].second;
            if (l == -1 && v[i].second == 1)
            {
                l = v[i].first;
            }
            if (l != -1 && cnt <= 0)
            {
                ans += v[i].first - l;
                l = -1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}