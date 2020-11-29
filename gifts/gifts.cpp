#include <iostream>
#include <algorithm>
using namespace std;
struct gifts
{
    int p, s;
    int t;
} g[1005];
bool cmp(const gifts &a, const gifts &b)
{
    return a.t < b.t;
}
int main()
{
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i].p >> g[i].s;
        g[i].t = g[i].p + g[i].s;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        gifts q[1005];
        for (int j = 0; j < n; j++)
        {
            q[j].s = g[j].s;
            q[j].p = g[j].p;
            q[j].t = g[j].t;
        }
        q[i].p /= 2;
        q[i].t = q[i].p + q[i].s;
        int tmp = 0, np = 0;
        sort(q, q + n, cmp);
        for (int j = 0; j < n; j++)
        {
            if (np + q[j].t <= b)
            {
                tmp++;
                np += q[j].t;
            }
            else
            {
                break;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}