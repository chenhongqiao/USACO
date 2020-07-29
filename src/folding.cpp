#include <bits/stdc++.h>
using namespace std;
vector<int> r;
int n, l;
bool is_ok(double k, int lp, int rp)
{
    while (lp >= 0 && rp < n)
    {
        if (k - 1.0 * r[lp] != 1.0 * r[rp] - k)
        {
            return false;
        }
        lp--;
        rp++;
    }
    return true;
}
int main()
{

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        r.push_back(tmp);
    }
    sort(r.begin(), r.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        double k = r[i] + (r[i + 1] - r[i]) / 2.0;
        if (is_ok(k, i, i + 1))
        {
            ans++;
        }
        if (i != n - 2 && r[i] + (r[i + 2] - r[i]) / 2.0 == r[i + 1])
        {
            if (is_ok(r[i + 1], i, i + 2))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}