// 123 Triangle
#include <iostream>
using namespace std;
int f2[1000005];
void f2cnt(int n)
{
    for (int i = 0; i <= n; i++)
    {
        int p = i;
        while (p % 2 == 0 && p > 0)
        {
            p /= 2;
            f2[i]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        f2[i] += f2[i - 1];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    f2cnt(n);
    int a[n];
    bool has1 = false;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0' - 1;
        if (a[i] == 1)
        {
            has1 = true;
        }
    }
    if (has1)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (f2[n - 1] - f2[i] - f2[n - 1 - i] <= 0)
            {
                cnt += a[i] % 2;
            }
        }
        if (cnt % 2)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (f2[n - 1] - f2[i] - f2[n - 1 - i] <= 0)
            {
                cnt += a[i] / 2 % 2;
            }
        }
        if (cnt % 2)
        {
            cout << 2 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}