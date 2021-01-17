#include <bits/stdc++.h>
using namespace std;
vector<int> c;
int main()
{
    //freopen("herding.in", "r", stdin);
    //freopen("herding.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        c.push_back(p);
    }
    sort(c.begin(), c.end());
    int ansmin = 100000000;
    for (int i = 0; i < n; i++)
    {
        int e = upper_bound(c.begin(), c.end(), c[i] + n - 1) - c.begin();
        if ((i == 0 || e >= n) && c[e - 1] != c[i] + n - 1)
        {
            continue;
        }
        ansmin = min(ansmin, n - (e - i));
    }
    int ansmax = max((c[n - 2] - c[0] - 1) - (n - 3), (c[n - 1] - c[1] - 1) - (n - 3));
    cout << ansmin << endl;
    cout << ansmax << endl;
    return 0;
}