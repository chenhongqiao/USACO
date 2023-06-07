#include <iostream>
using namespace std;
int n, q;
int t[5005];
long long ans[5005][5005];
int m[2000010];
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int c = t[i] + t[j];
            if (c >= -1000000 && c <= 1000000)
            {
                ans[i][j] = m[-c + 1000001];
            }
            m[t[j] + 1000001]++;
        }
        for (int j = i + 1; j < n; j++)
        {
            m[t[j] + 1000001]--;
        }
    }
    for (int i = n - 3; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            ans[i][j] += ans[i + 1][j] + ans[i][j - 1] - ans[i + 1][j - 1];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << ans[l - 1][r - 1] << endl;
    }
    return 0;
}
