#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
bool v[100005];
int main()
{
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    queue<int> q;
    q.push(1);
    v[1] = true;
    while (!q.empty())
    {
        int fa = q.front();
        int cnt = 0;
        for (int i = 0; i < g[fa].size(); i++)
        {
            if (!v[g[fa][i]])
            {
                v[g[fa][i]] = true;
                cnt++;
                q.push(g[fa][i]);
            }
        }
        if (fa == 1)
        {
            cnt += 1;
        }
        else
        {
            cnt += 2;
        }
        ans = max(ans, cnt);
        q.pop();
    }
    cout << ans << endl;
    return 0;
}