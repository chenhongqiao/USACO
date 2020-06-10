#include <iostream>
#include <algorithm>
using namespace std;
long long t1[1000005];
long long can[1000005];
string str;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int cn = 0;
    int n, f;
    cin >> n >> f;
    cin >> str;
    int l = 0, r = -1;
    for (int i = 0; i < n; i++)
    {
        int k = 1;
        if (i <= r)
        {
            k = min(t1[l + r - i], (long long)r - i);
        }
        while (i + k < n && i - k >= 0 && str[i - k] == str[i + k])
        {
            k++;
        }
        t1[i] = k--;
        can[cn] = t1[i] * 2 - 1;
        cn++;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    sort(can, can + cn, cmp);
    long long ans = 1;
    for (int i = 0; i < min(f, n); i++)
    {
        cout << can[i] << endl;
        ans %= 19930726;
        ans *= (can[i] % 19930726);
        ans %= 19930726;
    }
    cout << ans % 19930726 << endl;

    return 0;
}