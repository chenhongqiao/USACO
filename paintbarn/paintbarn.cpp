#include <bits/stdc++.h>
using namespace std;
int psum[1005][1005];
int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++)
        {
            psum[j][y1] += 1;
            psum[j][y2] -= 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 1000; i++)
    {
        int cnt = 0;
        for (int j = 0; j <= 1000; j++)
        {
            cnt += psum[i][j];
            if (cnt == k)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}