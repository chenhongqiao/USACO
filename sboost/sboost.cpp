#include <iostream>
#include <algorithm>
using namespace std;
long long f, m;
int n;
struct parts
{
    int f, m;
    double v;
    int n;
} p[10005];
int ans[10005];
bool cmp(const parts &a, const parts &b)
{
    return a.v > b.v;
}
int main()
{
    cin >> f >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].f >> p[i].m;
        p[i].v = 1.0 * (double)p[i].f / p[i].m;
        p[i].n = i;
    }
    sort(p, p + n, cmp);
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].v > 1.0 * (double)f / m)
        {
            ans[num] = p[i].n;
            num++;
            f += p[i].f;
            m += p[i].m;
        }
    }
    if (num == 0)
    {
        cout << "NONE" << endl;
    }
    else
    {
        sort(ans, ans + num);
        for (int i = 0; i < num; i++)
        {
            cout << ans[i] + 1 << endl;
        }
    }
    return EXIT_SUCCESS;
}