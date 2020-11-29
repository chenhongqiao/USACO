#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> c; //first: posision second: speed
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p, s;
        cin >> p >> s;
        c.push_back({p, s});
    }
    int ms = 1000000005;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (c[i].second <= ms)
        {
            ms = c[i].second;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}