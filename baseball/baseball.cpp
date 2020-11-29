#include <iostream>
#include <algorithm>
using namespace std;
int c[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c, c + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int f = lower_bound(c, c + n, c[j] + (c[j] - c[i])) - c;
            int t = upper_bound(c, c + n, c[j] + 2 * (c[j] - c[i])) - c;
            ans += t - f;
        }
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}