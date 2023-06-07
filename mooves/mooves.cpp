// Dance Mooves
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int n, k;
long long m;
struct node
{
    int id, lk, rd;
};
vector<pair<int, int>> g;
vector<pair<int, int>> kvis[100005];
vector<node> cyc[100005];
vector<int> effn[100005];
int sim[100005];
bool cvis[100005];
int ans[100005];
void add_to_cycle(const int st, const int cid, const int dep)
{
    if (cvis[st])
    {
        return;
    }
    cvis[st] = true;
    effn[cid].push_back(cyc[cid].size());
    for (int i = 0; i < kvis[st].size(); i++)
    {
        cyc[cid].push_back({kvis[st][i].first, kvis[st][i].second, dep});
    }
    add_to_cycle(kvis[st].rbegin()->first, cid, dep + 1);
}
void solve_cycle(int cid)
{
    int h = 0, t = 1;
    int cl = cyc[cid].size();
    int rdc = cyc[cid].rbegin()->rd + 1;
    unordered_map<int, int> freq;
    int cnt = 1;
    freq[cyc[cid][0].id]++;
    for (int i = 0; i < effn[cid].size(); i++)
    {
        if (effn[cid][i] >= t)
        {
            freq.clear();
            cnt = 1;
            h = effn[cid][i];
            t = h + 1;
            freq[freq[cyc[cid][h].id]]++;
        }
        else
        {
            while (h != effn[cid][i])
            {
                freq[cyc[cid][h].id]--;
                if (freq[cyc[cid][h].id] == 0)
                {
                    cnt--;
                    freq.erase(cyc[cid][h].id);
                }
                h++;
            }
        }
        while (t % cl != h && (((long long)cyc[cid][t % cl].rd - cyc[cid][h].rd + rdc) % rdc) * k + cyc[cid][t % cl].lk <= m)
        {
            if (freq.find(cyc[cid][t % cl].id) == freq.end())
            {
                cnt++;
            }
            freq[cyc[cid][t % cl].id]++;
            t++;
        }
        ans[cyc[cid][h].id] = cnt;
    }
}
int main()
{
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        g.push_back({u, v});
    }
    for (int i = 1; i <= n; i++)
    {
        sim[i] = i;
        kvis[i].push_back({i, 0});
    }
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first;
        int v = g[i].second;
        kvis[sim[u]].push_back({v, i + 1});
        kvis[sim[v]].push_back({u, i + 1});
        int tmp = sim[u];
        sim[u] = sim[v];
        sim[v] = tmp;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (kvis[i].size() > 1)
        {
            if (!cvis[i])
            {
                add_to_cycle(i, cnt, 0);
                cnt++;
            }
        }
        else
        {
            ans[i] = 1;
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        solve_cycle(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}