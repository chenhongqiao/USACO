#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int po[100005];
int na[100005];
bool cmp(const int a, const int b)
{
    return a > b;
}
int main()
{
    int t, n;
    cin >> t >> n;
    int pn = 0, nn = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp < 0)
        {
            na[nn] = tmp;
            nn++;
        }
        else
        {
            po[pn] = tmp;
            pn++;
        }
    }
    sort(po, po + pn);
    sort(na, na + nn, cmp);
    int tnow = 0;
    int posnow = 0;
    int an = 0, ap = 0;
    int ans = 0;
    while (tnow < t)
    {
        if (an >= nn || (ap < pn && po[ap] < (-na[an])))
        {
            tnow += abs(posnow - po[ap]);
            posnow = po[ap];
            ap++;
            ans++;
        }
        else if (an < nn)
        {
            tnow += abs(posnow - na[an]);
            posnow = na[an];
            ans++;
            an++;
        }
        else
        {
            break;
        }
    }
    cout << min(ans - 1, n) << endl;
    return 0;
}