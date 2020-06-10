#include <iostream>
using namespace std;
int p[100005];
int a[100005], b[100005], c[100005];
int t[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i < m - 1; i++)
    {
        int u = min(p[i], p[i + 1]);
        int v = max(p[i], p[i + 1]);
        t[u]++;
        t[v]--;
    }
    for (int i = 1; i < n; i++)
    {
        t[i] += t[i - 1];
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        long long orz = 1;
        ans += min(orz * a[i] * t[i], orz * b[i] * t[i] + c[i]);
    }
    cout << ans << endl;
    return 0;
}