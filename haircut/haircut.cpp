#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int tree[100005];
long long psum[100005];
long long ans[100005];
void update(int p, int v)
{
    while (p <= n + 1)
    {
        tree[p] += v;
        p += p & -p;
    }
}
int sum(int p)
{
    int s = 0;
    while (p > 0)
    {
        s += tree[p];
        p -= p & -p;
    }
    return s;
}
int main()
{
    //freopen("haircut.in", "r", stdin);
    //freopen("haircut.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]++;
    }
    for (int i = 0; i < n; i++)
    {
        update(a[i], 1);
        int b = sum(n + 1) - sum(a[i]);
        psum[a[i]] += b;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            ans[i] = ans[i - 1];
        }
        ans[i] += psum[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}