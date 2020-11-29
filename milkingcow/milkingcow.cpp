#include <iostream>
using namespace std;
int s[1000005];
int main()
{
    int n, k = 0;
    cin >> n;
    int sn = 100000000;
    for (int i = 0; i < n; i++)
    {
        int h, t;
        cin >> h >> t;
        s[h]++;
        s[t]--;
        k = max(k, t);
        sn = min(sn, h);
    }
    for (int i = 1; i <= k; i++)
    {
        s[i] += s[i - 1];
    }
    int tmp = 0;
    int ans = 0;
    for (int i = sn; i <= k + 1; i++)
    {
        if (s[i] == 0)
        {
            ans = max(tmp, ans);
            tmp = 0;
        }
        else
        {
            tmp++;
        }
    }
    cout << ans << " ";
    tmp = 0, ans = 0;
    for (int i = sn + 1; i <= k; i++)
    {
        if (s[i] != 0)
        {
            ans = max(tmp, ans);
            tmp = 0;
        }
        else
        {
            tmp++;
        }
    }
    cout << ans << endl;
    return 0;
}