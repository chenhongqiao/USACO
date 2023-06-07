// Springboards
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
map<int, vector<pair<int, int>>> m;
vector<pair<int, int>> nd;
int tp[200005];
long long dp[200005];
set<pair<int, int>> s;
int dis(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
int main()
{
    for (int i = 0; i < 200005; i++)
    {
        dp[i] = 5000000005;
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    int cnt = 0;
    for (int i = 0; i < p; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        nd.push_back({x1, y1});
        m[x1].push_back({y1, cnt});
        nd.push_back({x2, y2});
        m[x2].push_back({y2, cnt + 1});
        tp[cnt] = cnt + 1;
        tp[cnt + 1] = -1;
        cnt += 2;
    }
    nd.push_back({n, n});
    m[n].push_back({n, cnt});
    tp[cnt] = -1;
    for (auto &[x, l] : m)
    {
        sort(l.begin(), l.end());
    }
    for (auto &[x, l] : m)
    {
        for (auto &[y, t] : l)
        {
            auto it = s.upper_bound({y, 2000000005});
            long long wlk = 5000000005;
            if (s.empty() || it == s.begin())
            {
                wlk = dis(0, 0, x, y);
            }
            else
            {
                wlk = dis(nd[prev(it)->second].first, nd[prev(it)->second].second, x, y) + dp[prev(it)->second];
            }
            dp[t] = min(dp[t], wlk);
            if (tp[t] != -1)
            {
                dp[tp[t]] = min(dp[tp[t]], wlk);
            }
            if (it == s.begin() || dp[prev(it)->second] + dis(nd[prev(it)->second].first, nd[prev(it)->second].second, x, y) > dp[t])
            {
                vector<set<pair<int, int>>::iterator> rm;
                if (!s.empty())
                {
                    if (it != s.begin() && prev(it)->first == y)
                    {
                        rm.push_back(prev(it));
                    }
                    while (it != s.end() && dp[t] + abs(nd[it->second].second - y) <= dp[it->second] + abs(nd[it->second].first - x))
                    {
                        rm.push_back(it);
                        it++;
                    }
                    for (auto rt : rm)
                    {
                        s.erase(rt);
                    }
                }
                s.insert({y, t});
            }
        }
    }
    cout << dp[cnt] << endl;
    return 0;
}