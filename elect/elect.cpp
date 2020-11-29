#include <iostream>
#include <algorithm>
using namespace std;
struct vote
{
    int a, b, n;
} v[50005];
bool cmp(const vote &a, const vote &b)
{
    return a.a > b.a;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].a >> v[i].b;
        v[i].n = i;
    }
    sort(v, v + n, cmp);
    int ans = 0, ansvote = -1000000;
    for (int i = 0; i < k; i++)
    {
        if (v[i].b > ansvote)
        {
            ansvote = v[i].b;
            ans = v[i].n;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}