#include <bits/stdc++.h>
using namespace std;
int s[25];
int a = 0, b = 0, c = 0;
int n;
int ans = 10000000;
void func(int dep)
{
    if (a >= ans || b >= ans || c >= ans)
    {
        return;
    }
    if (dep >= n)
    {
        if (a >= b && b >= c)
        {
            ans = min(ans, a);
        }
        return;
    }
    a += s[dep];
    func(dep + 1);
    a -= s[dep];
    b += s[dep];
    func(dep + 1);
    b -= s[dep];
    c += s[dep];
    func(dep + 1);
    c -= s[dep];
    return;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    func(0);
    cout << ans << endl;
    return 0;
}