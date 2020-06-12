#include <iostream>
#include <cmath>
using namespace std;
struct table
{
    long long x, y;
} t[1005];
struct cow
{
    long long x, y;
    bool o = false;
} c[1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].x >> c[i].y;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i].x >> t[i].y;
    }
    for (int i = 0; i < m; i++)
    {
        double fd = 1000000000.0;
        int fs;
        for (int j = 0; j < n; j++)
        {
            if (c[j].o)
            {
                continue;
            }
            long long d = abs(t[i].x - c[j].x) * abs(t[i].x - c[j].x) + abs(t[i].y - c[j].y) * abs(t[i].y - c[j].y);
            double tmp = sqrt(1.0 * d);
            if (tmp < fd)
            {
                fd = tmp;
                fs = j;
            }
        }
        c[fs].o = true;
    }
    bool ha = false;
    for (int i = 0; i < n; i++)
    {
        if (!c[i].o)
        {
            ha = true;
            cout << i + 1 << endl;
        }
    }
    if (!ha)
    {
        cout << 0 << endl;
    }
    return 0;
}