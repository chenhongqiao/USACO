#include <iostream>
#include <algorithm>
using namespace std;
struct cow
{
    int num, milk;
} c[100005];
bool cmp(const cow &a, const cow &b)
{
    return a.milk < b.milk;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].num >> c[i].milk;
    }
    sort(c, c + n, cmp);
    int h = 0, t = n - 1;
    int ans = 0;
    while (h <= t)
    {
        ans = max(ans, c[h].milk + c[t].milk);
        int tmp = min(c[h].num, c[t].num);
        c[h].num -= tmp;
        c[t].num -= tmp;
        if (c[h].num <= 0)
            h++;
        if (c[t].num <= 0)
            t--;
    }
    cout << ans << endl;
    return 0;
}