#include <bits/stdc++.h>
using namespace std;
bool bk[100005];
int pfx[100005];
int main()
{
    int n, k, b;
    cin >> n >> k >> b;
    for (int i = 0; i < b; i++)
    {
        int l;
        cin >> l;
        bk[l - 1] = true;
    }
    if (!bk[0])
    {
        pfx[0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        pfx[i] = pfx[i - 1];
        if (!bk[i])
        {
            pfx[i]++;
        }
    }
    int ans = 100000000;
    for (int i = 0; i < n - k; i++)
    {
        int tmp = k - (pfx[i + k] - pfx[i]);
        if (tmp > 0)
        {
            ans = min(tmp, ans);
        }
    }
    cout << ans << endl;
}