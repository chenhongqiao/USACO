#include <iostream>
#include <algorithm>
using namespace std;
int d[50005];
int dp1[50005], dp2[50005];
int dis1[50005], dis2[50005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d, d + n);
    /*for (int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;*/

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (d[j] - d[i] <= k && j < n)
            j++;
        dp1[i] = j - i;
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << dp1[i] << " ";
    }
    cout << endl;*/
    j = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        while (d[i] - d[j] <= k && j >= 0)
            j--;
        dp2[i] = i - j;
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << dp2[i] << " ";
    }
    cout << endl;*/
    for (int i = 1; i < n; i++)
    {
        dp2[i] = max(dp2[i], dp2[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        dp1[i] = max(dp1[i], dp1[i + 1]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp1[i] + dp2[i + 1]);
    }
    if (ans > n)
    {
        cout << n << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}