// Timeline
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int in[100005];
vector<pair<int, int>> g[100005];
int ans[100005];
queue<int> q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> ans[i];
    }
    for (int i = 0; i < c; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        g[a].push_back({b, x});
        in[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        for (auto v : g[q.front()])
        {
            ans[v.first] = max(ans[v.first], ans[q.front()] + v.second);
            in[v.first]--;
            if (in[v.first] == 0)
            {
                q.push(v.first);
            }
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}