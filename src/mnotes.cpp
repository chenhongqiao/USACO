#include <iostream>
#include <algorithm>
using namespace std;
struct music
{
    int b, r;
} m[50005];
bool cmp(const music &a, const int v)
{
    return a.b <= v;
}
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        m[i].b = tmp;
        m[i].r = i + 1;
        if (i != 0)
        {
            m[i].b += m[i - 1].b;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        int s = lower_bound(m, m + n, t, cmp) - m;
        cout << m[s].r << endl;
    }
    return EXIT_SUCCESS;
}