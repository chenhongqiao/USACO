#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
vector<pair<int, long long>> d[5005]; //First: index Second: relevance
int bfs(int fa, int k)
{
    queue<pair<int, int>> q;
    bool v[5005] = {false};
    v[fa] = true;
    q.push({fa, 2000000000});
    int ans = 0;
    while (!q.empty())
    {
        int kf = q.front().first;
        long long kr = q.front().second;
        for (int i = 0; i < d[kf].size(); i++)
        {
            long long tmp = min(kr, d[kf][i].second);
            if (!v[d[kf][i].first] && tmp >= k)
            {
                v[d[kf][i].first] = true;
                q.push({d[kf][i].first, tmp});
                ans++;
            }
        }
        q.pop();
    }
    return ans;
}
int main()
{
    //freopen("mootube.in", "r", stdin);
    //freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int p, q;
        long long r;
        cin >> p >> q >> r;
        d[p].push_back({q, r});
        d[q].push_back({p, r});
    }
    for (int i = 0; i < q; i++)
    {
        int k, v;
        cin >> k >> v;
        cout << bfs(v, k) << endl;
    }
    return 0;
}