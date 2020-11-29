#include <iostream>
#include <algorithm>
using namespace std;
struct toy
{
    int j, p;
    double v;
    int order;
} t[25005];
bool cmp(const toy &a, const toy &b)
{
    return a.v > b.v;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].j >> t[i].p;
        t[i].v = 1.0 * t[i].j / t[i].p;
        t[i].order = i;
    }
    sort(t, t + n, cmp);
    int ans = t[0].p + t[1].p + t[2].p;
    cout << ans << endl;
    cout << t[0].order + 1 << endl;
    cout << t[1].order + 1 << endl;
    cout << t[2].order + 1 << endl;
    return 0;
}