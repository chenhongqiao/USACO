#include <bits/stdc++.h>
using namespace std;
int s[25];
int a[25];
int b[25];
int main()
{
    const int n = 20;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i];
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = s[i];
    }

    int as = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] != 0)
        {
            as++;
            a[i - 1] = 1 - s[i - 1];
            a[i] = 1 - a[i];
            a[i + 1] = 1 - a[i + 1];
        }
    }
    int bs = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (b[i + 1] != 0)
        {
            bs++;
            b[i + 1] = 1 - b[i + 1];
            b[i] = 1 - b[i];
            b[i - 1] = 1 - b[i - 1];
        }
    }
    cout << min(as, bs) << endl;
    return 0;
}