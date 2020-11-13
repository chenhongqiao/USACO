#include <bits/stdc++.h>
using namespace std;
vector<int> s;
long long ans = 0;
void func(int h, int t, int dep) //including h, not including t
{
    if (t - h == 2)
    {
        long long tmp = 1;
        ans += (tmp * s[h] * s[h + 1]);
        return;
    }
    if (t - h <= 1)
    {
        return;
    }
    func(h, h + (t - h + 1) / 2, dep + 1);
    func(h + (t - h + 1) / 2, t, dep + 1);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s.push_back(i + 1);
    }
    func(0, n, 0);
    cout << ans << endl;
    return 0;
}