#include <bits/stdc++.h>
using namespace std;
int n, k;
int pc[100005];
vector<int> g[100005];
bool v[100005];
const long long mod = 1000000007;
int m[4][100005];
long long dfs(int lc, int f)
{
    if (m[lc][f])
    {
        return m[lc][f];
    }
    if (pc[f])
    {
        if (lc == pc[f])
        {
            return 0;
        }
        long long cnt = 1;
        for (int i = 0; i < g[f].size(); i++)
        {
            if (!v[g[f][i]])
            {
                v[g[f][i]] = true;
                cnt *= (dfs(pc[f], g[f][i]) % mod);
                cnt %= mod;
                v[g[f][i]] = false;
            }
        }
        m[lc][f] = cnt;
        return cnt;
    }
    long long cnta = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (i != lc)
        {
            long long cnt = 1;
            for (int j = 0; j < g[f].size(); j++)
            {
                if (!v[g[f][j]])
                {
                    v[g[f][j]] = true;
                    cnt *= (dfs(i, g[f][j]) % mod);
                    cnt %= mod;
                    v[g[f][j]] = false;
                }
            }
            cnta += cnt;
            cnta %= mod;
        }
    }
    m[lc][f] = cnta;
    return cnta;
}
int main()
{
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < k; i++)
    {
        int b, c;
        cin >> b >> c;
        pc[b] = c;
    }
    v[1] = true;
    cout << dfs(0, 1) << endl;
    return 0;
}