#include <bits/stdc++.h>
using namespace std;
vector<int> r[20010];
vector<int> c[20010];
vector<long long> rs[20010];
vector<long long> rsr[20010];
vector<long long> cs[20010];
vector<long long> csr[20010];
vector<pair<int, int>> p;
int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        r[x + 10000].push_back(y + 10000);
        c[y + 10000].push_back(x + 10000);
        p.push_back({x + 10000, y + 10000});
    }
    for (int i = 0; i < 20001; i++)
    {
        if (r[i].size() != 0)
        {
            sort(r[i].begin(), r[i].end());
        }
    }
    for (int i = 0; i < 20001; i++)
    {
        if (c[i].size() != 0)
        {
            sort(c[i].begin(), c[i].end());
        }
    }
    for (int i = 0; i < 20001; i++)
    {
        if (r[i].size() != 0)
        {
            rs[i].reserve(r[i].size() + 1);
            rsr[i].reserve(r[i].size() + 1);
            for (int j = 0; j < r[i].size(); j++)
            {
                if (j == 0)
                {
                    rs[i][j] = 0;
                }
                else
                {
                    rs[i][j] = (rs[i][j - 1] + (r[i][j] - r[i][j - 1]) * j);
                }
            }
            for (int j = r[i].size() - 1; j >= 0; j--)
            {
                if (j == r[i].size() - 1)
                {
                    rsr[i][j] = 0;
                }
                else
                {
                    rsr[i][j] = (rsr[i][j + 1] + (r[i][j + 1] - r[i][j]) * (r[i].size() - 1 - j));
                }
            }
        }
    }
    for (int i = 0; i < 20001; i++)
    {
        if (c[i].size() != 0)
        {
            cs[i].reserve(c[i].size() + 1);
            csr[i].reserve(c[i].size() + 1);
            for (int j = 0; j < c[i].size(); j++)
            {
                if (j == 0)
                {
                    cs[i][j] = 0;
                }
                else
                {
                    cs[i][j] = (cs[i][j - 1] + (c[i][j] - c[i][j - 1]) * j);
                }
            }
            for (int j = c[i].size() - 1; j >= 0; j--)
            {
                if (j == c[i].size() - 1)
                {
                    csr[i][j] = 0;
                }
                else
                {
                    csr[i][j] = (csr[i][j + 1] + (c[i][j + 1] - c[i][j]) * (c[i].size() - 1 - j));
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int kx = p[i].first;
        int ky = p[i].second;
        int rp = lower_bound(r[kx].begin(), r[kx].end(), ky) - r[kx].begin();
        int cp = lower_bound(c[ky].begin(), c[ky].end(), kx) - c[ky].begin();
        long long aa = (rs[kx][rp] * cs[ky][cp]) % 1000000007;
        long long ba = (rs[kx][rp] * csr[ky][cp]) % 1000000007;
        long long ca = (rsr[kx][rp] * cs[ky][cp]) % 1000000007;
        long long da = (rsr[kx][rp] * csr[ky][cp]) % 1000000007;
        ans += (aa + ba + ca + da);
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}