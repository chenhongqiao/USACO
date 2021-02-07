#include <bits/stdc++.h>
using namespace std;
bool dp1[5000005];
bool dp2[5000005];
int main()
{
    //freopen("feast.in", "r", stdin);
    //freopen("feast.out", "w", stdout);
    int t, a, b;
    cin >> t >> a >> b;
    dp1[0] = true;
    for (int i = 1; i <= t; i++)
    {
        if ((i - a >= 0 && dp1[i - a]) || (i - b >= 0 && dp1[i - b]))
        {
            dp1[i] = true;
        }
    }
    dp2[0] = true;
    for (int i = 1; i <= t; i++)
    {
        if ((i - a >= 0 && dp2[i - a]) || (i - b >= 0 && dp2[i - b]) || (i * 2 <= t && dp1[i * 2] || (i * 2 + 1 <= t && dp1[i * 2 + 1])))
        {
            dp2[i] = true;
        }
    }
    for (int i = t; i >= 0; i--)
    {
        if (dp2[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}