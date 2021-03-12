#include <bits/stdc++.h>
using namespace std;
int n;
const int m = 1000000;
int psum[1000005];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        psum[v]++;
    }
    for (int i = 0; i <= m + 1; i++)
    {
        if (i != 0)
        {
            psum[i] += psum[i - 1];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int op = 0;
        for (int j = 1; i * j <= m; j++)
        {
            int s = (i * j) - 1;
            int e = min(i * (j + 1) - 1, m + 1);
            op += (psum[e] - psum[s]) % 2;
        }
        if (op > 2)
        {
            continue;
        }
        if (op == 1 && (psum[min(i * 2 - 1, m + 1)] - psum[i - 1]) % 2 == 1)
        {
            ans += psum[min(i * 2 - 1, m + 1)] - psum[i - 1];
        }
        else if (op == 2)
        {
            for (int j = 2; i * j <= m; j++)
            {
                int ks = (i * j - 1);
                int ke = min(i * (j + 1) - 1, m + 1);
                int ps = (i * (j - 1) - 1);
                if ((psum[ke] - psum[ks]) % 2 == 1 && (psum[ks] - psum[ps]) % 2 == 1)
                {
                    ans += psum[ke] - psum[ks];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}