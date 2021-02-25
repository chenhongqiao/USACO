#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
int n, q;
struct path
{
    int r;
    int a, b;
};
vector<path> p;
vector<pair<int, int>> rq;
vector<pair<int, int>> srq;
bool pcomp(path a, path b)
{
    return a.r > b.r;
}
bool qcomp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
umap<int, umap<int, int>> ans;
int f[100005];
int h[100005];
int cnt[100005];
int find(int cur)
{
    if (f[cur] != cur)
    {
        f[cur] = find(f[cur]);
    }
    return f[cur];
}
void add(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if (h[fa] > h[fb])
    {
        f[fb] = fa;
        cnt[fa] += (cnt[fb] + 1);
        h[fa] = max(h[fa], h[fb] + 1);
    }
    else
    {
        f[fa] = fb;
        cnt[fb] += (cnt[fa] + 1);
        h[fb] = max(h[fb], h[fa] + 1);
    }
}
int main()
{
    //freopen("mootube.in", "r", stdin);
    //freopen("mootube.out", "w", stdout);
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, r;
        cin >> a >> b >> r;
        p.push_back({r, a, b});
    }
    for (int i = 0; i < q; i++)
    {
        int k, v;
        cin >> k >> v;
        rq.push_back({k, v});
        srq.push_back({k, v});
    }
    sort(srq.begin(), srq.end(), qcomp);
    sort(p.begin(), p.end(), pcomp);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        cnt[i] = 0;
    }
    int ph = 0;
    for (int i = 0; i < q; i++)
    {
        while (p[ph].r >= srq[i].first)
        {
            add(p[ph].a, p[ph].b);
            ph++;
        }
        ans[srq[i].first][srq[i].second] = cnt[find(srq[i].second)];
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[rq[i].first][rq[i].second] << endl;
    }
    return 0;
}