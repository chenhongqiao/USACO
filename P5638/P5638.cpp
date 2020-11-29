#include <iostream>
using namespace std;
long long a[1000005];
long long sum[1000005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    long long ans = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (i + k > n - 1)
        {
            ans = max(ans, sum[n - 1] - sum[i]);
        }
        else
        {
            ans = max(ans, sum[i + k] - sum[i]);
        }
    }
    cout << sum[n - 1] - ans << endl;
}