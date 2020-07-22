#include <bits/stdc++.h>
using namespace std;
double s[100005];
int main()
{
    int m, q;
    cin >> m >> q;
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        sort(s + l, s + r);
        double cnt = 0;
        for (int j = 0; j < (r - l + 1) / 2; j++)
        {
            cnt += (s[l + j] - floor(s[l + j]) + ceil(s[r - j]) - s[r - j]);
        }
        cout << cnt << endl;
    }
}