#include <iostream>
#include <cmath>
using namespace std;
struct marathon2
{
    int x, y;
} m[100005];
int d[100005];
int t[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i].x >> m[i].y;
    }
    for (int i = 1; i < n; i++)
    {
        d[i] = d[i - 1] + (abs(m[i].x - m[i - 1].x) + abs(m[i].y - m[i - 1].y));
    }
    for (int i = 0; i < n; i++)
    {
        t[i] = abs(m[i].x - m[i + 2].x) + abs(m[i].y - m[i + 2].y);
    }
    int ans = 1000000000;
    for (int i = 1; i < n - 1; i++)
    {
        ans = min(ans, d[i - 1] + d[n - 1] - d[i + 1] + t[i - 1]);
    }
    cout << ans << endl;
    return 0;
}