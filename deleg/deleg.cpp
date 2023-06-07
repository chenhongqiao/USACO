// Delegation
#include <iostream>
#include <vector>
using namespace std;
int n;
int cnt[100005];
vector<int> g[100005];
vector<int> num[100005];
bool vis[100005];
int dfs(int u)
{
    for (int v : g[u])
    {
        if (!vis[v])
        {
            vis[v] = true;
            int tmp = dfs(v);
            cnt[u] += tmp;
            num[u].push_back(tmp);
        }
    }
    cnt[u]++;
    if (cnt[u] != n)
    {
        num[u].push_back(n - cnt[u]);
    }
    return cnt[u];
}
bool check(int k)
{
    int m[100005] = {0};
    for (int i = 1; i <= n; i++)
    {
        int p = 0;
        for (int v : num[i])
        {
            if (v % k != 0)
            {
                int t = k - (v % k);
                if (m[t] > 0)
                {
                    m[t]--;
                    p--;
                }
                else
                {
                    m[v % k]++;
                    p++;
                }
            }
        }
        if (p > 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1] = true;
    dfs(1);
    for (int i = 1; i <= n - 1; i++)
    {
        if ((n - 1) % i != 0 || !check(i))
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }
    cout << endl;
    return 0;
}