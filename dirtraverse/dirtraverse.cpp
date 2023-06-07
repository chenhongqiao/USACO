// Directory Traversal
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<string, int>> nd;
vector<int> g[100005];
long long dp[100005];
int gen_stats(int f)
{
    if (nd[f].second == -1)
    {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < g[f].size(); i++)
    {
        cnt += gen_stats(g[f][i]);
    }
    nd[f].second = cnt;
    return cnt;
}
long long calc_child_size(int f)
{
    if (nd[f].second == -1)
    {
        return nd[f].first.size();
    }
    else if (nd[f].second == 0)
    {
        return -9000000000000000000;
    }
    long long cnt = 0;
    for (int i = 0; i < g[f].size(); i++)
    {
        long long tmp = calc_child_size(g[f][i]) + (nd[g[f][i]].second != -1 ? nd[g[f][i]].second : 1) * (nd[f].first.size() + 1);
        if (tmp > 0)
        {
            cnt += tmp;
        }
    }
    return cnt;
}
void dfs(int f, int l)
{
    dp[f] = dp[l] + (nd[0].second - nd[f].second) * 3 - nd[f].second * (nd[f].first.size() + 1);
    for (int i = 0; i < g[f].size(); i++)
    {
        if (nd[g[f][i]].second != -1)
        {
            dfs(g[f][i], f);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    nd.push_back({"", 0});
    g[0].push_back(1);
    for (int i = 1; i <= n; i++)
    {
        string name;
        int m;
        cin >> name >> m;
        if (m == 0)
        {
            nd.push_back({name, -1});
        }
        else
        {
            nd.push_back({name, 0});
            for (int j = 0; j < m; j++)
            {
                int cd;
                cin >> cd;
                g[i].push_back(cd);
            }
        }
    }
    gen_stats(0);
    dp[0] = calc_child_size(0) - nd[0].second;
    dfs(1, 0);
    long long ans = 9000000000000000000;
    for (int i = 1; i <= n; i++)
    {
        if (nd[i].second != -1)
        {
            ans = min(ans, dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}