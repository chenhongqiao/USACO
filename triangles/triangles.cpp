#include <bits/stdc++.h>
#define umap unordered_map
#define f first
#define s second
using namespace std;
umap<int, vector<long long>> r;
umap<int, vector<long long>> c;
umap<int, vector<long long>> rsum;
umap<int, vector<long long>> rsumr;
umap<int, vector<long long>> csum;
umap<int, vector<long long>> csumr;
umap<int, umap<int, int>> cp;
const long long m = 1000000007;
int main()
{
    //freopen("triangles.in", "r", stdin);
    //freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        r[x].push_back(y);
        c[y].push_back(x);
        cp[y][x] = c[y].size() - 1;
    }
    for (auto i = r.begin(); i != r.end(); i++)
    {
        sort(i->s.begin(), i->s.end());
    }
    for (auto i = c.begin(); i != c.end(); i++)
    {
        sort(i->s.begin(), i->s.end());
    }
    for (auto i = r.begin(); i != r.end(); i++)
    {
        for (int j = 0; j < i->s.size(); j++)
        {
            if (j == 0)
            {
                rsum[i->f].push_back(0);
            }
            else
            {
                rsum[i->f].push_back(r[i->f][j] - r[i->f][0]);
                rsum[i->f][j] += rsum[i->f][j - 1];
            }
        }
        for (int j = i->s.size() - 1; j >= 0; j--)
        {
            if (j == i->s.size() - 1)
            {
                rsumr[i->f].push_back(0);
            }
            else
            {
                rsumr[i->f].push_back(r[i->f][i->s.size() - 1] - r[i->f][j]);
                rsumr[i->f][i->s.size() - 1 - j] += rsumr[i->f][i->s.size() - 1 - j - 1];
            }
        }
    }
    for (auto i = c.begin(); i != c.end(); i++)
    {
        for (int j = 0; j < i->s.size(); j++)
        {
            if (j == 0)
            {
                csum[i->f].push_back(0);
            }
            else
            {
                csum[i->f].push_back(c[i->f][j] - c[i->f][0]);
                csum[i->f][j] += csum[i->f][j - 1];
            }
        }
        for (int j = i->s.size() - 1; j >= 0; j--)
        {
            if (j == i->s.size() - 1)
            {
                csumr[i->f].push_back(0);
            }
            else
            {
                csumr[i->f].push_back(c[i->f][i->s.size() - 1] - c[i->f][j]);
                csumr[i->f][i->s.size() - 1 - j] += csumr[i->f][i->s.size() - 1 - j - 1];
            }
        }
    }
    long long ans = 0;
    for (auto i = r.begin(); i != r.end(); i++)
    {
        for (int j = 0; j < i->s.size(); j++)
        {
            int kx = i->f;
            int ky = i->s[j];
            int k = cp[ky][kx];
            long long aa = (*rsum[kx].rbegin() - *(rsum[kx].begin() += j)) * (*csum[ky].rbegin() - *(csum[ky].begin() += k));
            long long ba = (*rsumr[kx].rbegin() - *(rsumr[kx].rbegin() += j)) * (*csum[ky].rbegin() - *(csum[ky].begin() += k));
            long long ca = (*rsum[kx].rbegin() - *(rsum[kx].begin() += j)) * (*csumr[ky].rbegin() - *(csumr[ky].rbegin() += k));
            long long da = (*rsumr[kx].rbegin() - *(rsumr[kx].rbegin() += j)) * (*csumr[ky].rbegin() - *(csumr[ky].rbegin() += k));
            ans += (aa + ba + ca + da) % m;
        }
    }
    ans = ans % m;
    cout << ans << endl;
    return 0;
}