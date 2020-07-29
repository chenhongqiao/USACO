#include <bits/stdc++.h>
using namespace std;
map<string, map<string, int>> m;
pair<string, string> p[200005];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
        ans += m[p[i].first.substr(0, 2)][p[i].second];
        if (p[i].second != p[i].first.substr(0, 2))
        {
            m[p[i].second][p[i].first.substr(0, 2)]++;
        }
    }

    cout << ans << endl;
    return 0;
}