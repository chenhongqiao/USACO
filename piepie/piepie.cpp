// A Pie for a Pie
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, d;
int t[2][200005];
vector<pair<int, int>> st[2]; // f->tastiness s->id
struct state
{
    int g;   // giver
    int id;  // pie id
    int cnt; // # of exchanges
};
queue<state> q;
bool vis[200005];
int ans[200005];
int main()
{
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        t[0][i] = a;
        t[1][i] = b;
        st[1].push_back({b, i});
    }
    for (int i = n; i < n * 2; i++)
    {
        int a, b;
        cin >> a >> b;
        t[0][i] = a;
        t[1][i] = b;
        st[0].push_back({a, i});
    }
    sort(st[0].begin(), st[0].end());
    sort(st[1].begin(), st[1].end());
    for (int i = 0; i < n; i++)
    {
        if (t[1][i] == 0)
        {
            q.push({0, i, 0});
            vis[i] = true;
        }
    }
    for (int i = n; i < n * 2; i++)
    {
        if (t[0][i] == 0)
        {
            q.push({1, i, 0});
            vis[i] = true;
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        int cg = cur.g;
        int ct = t[cg][cur.id];
        int pg = cur.g ^ 1;
        if (cg == 0)
        {
            ans[cur.id] = cur.cnt + 1;
        }
        int cand = upper_bound(st[cg].begin(), st[cg].end(), make_pair(ct, 0x7FFFFFFF)) - st[cg].begin() - 1;
        while (cand >= 0 && ct - st[cg][cand].first <= d)
        {
            if (!vis[st[cg][cand].second])
            {
                q.push({pg, st[cg][cand].second, cur.cnt + 1});
                vis[st[cg][cand].second] = true;
            }
            cand -= 1;
        }
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}