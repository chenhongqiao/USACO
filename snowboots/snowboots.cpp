#include <bits/stdc++.h>
using namespace std;
int n, b;
int s[255];
struct boots
{
    int s, d;
};
vector<boots> p;
int m[255][255];
int dfs(int k, int l)
{
    if (m[k][l] != -1)
    {
        return m[k][l];
    }
    if (k == n + 1)
    {
        return 0;
    }
    int ans = 1000000000;
    int cnt = 0;
    for (int i = l; i < b; i++)
    {
        if (p[i].s >= s[k])
        {
            for (int j = 1; j <= p[i].d && k + j <= n + 1; j++)
            {
                if (p[i].s >= s[k + j])
                {
                    ans = min(ans, dfs(k + j, i) + cnt);
                }
            }
        }
        cnt++;
    }
    m[k][l] = ans;
    return m[k][l];
}
int main()
{
    //freopen("snowboots.in", "r", stdin);
    //freopen("snowboots.out", "w", stdout);
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < b; i++)
    {
        int s, d;
        cin >> s >> d;
        p.push_back({s, d});
    }
    for (int i = 0; i < 255; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            m[i][j] = -1;
        }
    }
    cout << dfs(0, 0) << endl;
    return 0;
}