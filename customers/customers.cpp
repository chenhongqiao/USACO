#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> c;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int at, lt;
        cin >> at >> lt;
        c.push_back({at, 1});
        c.push_back({lt, -1});
    }
    sort(c.begin(), c.end());
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < c.size(); i++)
    {
        cnt += c[i].second;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}