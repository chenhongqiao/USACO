#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[100005];
pair<int, int> c[100005];
int ans[100005];
int cnt = 0;
void take(int u)
{
    if (s[c[u].first] == -1)
    {
        s[c[u].first] = u;
    }
    else if (s[c[u].first] < u)
    {
        take(s[c[u].first]);
        s[c[u].first] = u;
    }
    else if (s[c[u].second] == -1)
    {
        s[c[u].second] = u;
    }
    else if (s[c[u].second] < u)
    {
        take(s[c[u].second]);
        s[c[u].second] = u;
    }
    else
    {
        cnt--;
    }
}
int main()
{
    //freopen("cereal.in", "r", stdin);
    //freopen("cereal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        s[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;
        c[n - i - 1] = {f, s};
    }
    for (int i = 0; i < n; i++)
    {
        cnt++;
        take(i);
        ans[i] = cnt;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << ans[i] << endl;
    }
    return 0;
}