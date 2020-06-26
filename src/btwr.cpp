#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct bale
{
    int a, b;
} b[25];
int dp[25];
bool cmp(const bale &a, const bale &b)
{
    return a.a < b.a;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].a >> b[i].b;
    }
    sort(b, b + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (b[j].b < b[i].b)
            {
                tmp = max(tmp, dp[j]);
            }
        }
        dp[i] = tmp + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}