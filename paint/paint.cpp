#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
    int l, v;
    int s;
} p[500000];
bool cmp(const point &a, const point &b)
{
    if (a.l == b.l)
    {
        return a.s < b.s;
    }
    else
    {
        return a.l < b.l;
    }
}
int main()
{
    int n;
    cin >> n;
    int sub = 0;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        int m;
        char d;
        cin >> m >> d;
        if (d == 'R')
        {
            p[sub].l = now;
            p[sub].v = 1;
            p[sub].s = i;
            sub++;
            p[sub].l = now + m;
            p[sub].v = -1;
            p[sub].s = i;
            sub++;
            now += m;
        }
        else
        {
            p[sub].l = now;
            p[sub].v = -1;
            p[sub].s = i;
            sub++;
            p[sub].l = now - m;
            p[sub].v = 1;
            p[sub].s = i;
            sub++;
            now -= m;
        }
    }
    sort(p, p + sub, cmp);
    long long ans = 0;
    long long tmp = 0;
    for (int i = 0; i < sub; i++)
    {
        tmp += p[i].v;
        if (tmp >= 2)
        {
            ans += p[i + 1].l - p[i].l;
        }
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}