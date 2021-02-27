#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
umap<int, vector<int>> mp;
vector<pair<int, int>> c;
int n;
int tree[100005];
void add(int p)
{
    while (p <= n * 2)
    {
        tree[p] += 1;
        p += p & -p;
    }
}
int sum(int p)
{
    int s = 0;
    while (p > 0)
    {
        s += tree[p];
        p -= p & -p;
    }
    return s;
}
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main()
{
    //freopen("circlecross.in", "r", stdin);
    //freopen("circlecross.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n * 2; i++)
    {
        int k;
        cin >> k;
        mp[k].push_back(i);
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        int a = i->second[0];
        int b = i->second[1];
        c.push_back({min(a, b), max(a, b)});
    }
    sort(c.begin(), c.end(), comp);
    long long ans = 0;
    for (int i = 0; i < c.size(); i++)
    {
        ans += (sum(c[i].second) - sum(c[i].first));
        add(c[i].first);
    }
    cout << ans << endl;
    return 0;
}