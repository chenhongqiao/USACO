#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct gold
{
    int m, w;
    double v;
} g[105];
bool cmp(const gold &a, const gold &b)
{
    return a.v > b.v;
}
int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i].m >> g[i].w;
        g[i].v = 1.0 * g[i].w / g[i].m;
    }
    sort(g, g + n, cmp);
    int tm = 0;
    double tw = 0;
    for (int i = 0; i < n; i++)
    {
        if (tm + g[i].m > t)
        {
            tw += (((1.0 * t - tm) * 1.0) / g[i].m) * g[i].w;
            break;
        }
        else
        {
            tm += g[i].m;
            tw += g[i].w;
        }
    }
    cout << fixed << setprecision(2) << tw << endl;
    return 0;
}