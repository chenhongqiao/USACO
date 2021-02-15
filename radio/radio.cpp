#include <bits/stdc++.h>
using namespace std;
pair<int, int> f[1005];
pair<int, int> b[1005];
long long dp[1005][1005];
long long dist(pair<int, int> a, pair<int, int> b)
{
    long long one = 1;
    long long d = one * abs(a.first - b.first) * abs(a.first - b.first) + one * abs(a.second - b.second) * abs(a.second - b.second);
    return d;
}
int main()
{
    //freopen("radio.in", "r", stdin);
    //freopen("radio.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    n += 1;
    m += 1;
    int fx, fy, bx, by;
    cin >> fx >> fy >> bx >> by;
    string inst;
    cin >> inst;
    for (int i = 0; i < n; i++)
    {
        f[i] = {fx, fy};
        if (inst[i] == 'N')
        {
            fy++;
        }
        else if (inst[i] == 'S')
        {
            fy--;
        }
        else if (inst[i] == 'E')
        {
            fx++;
        }
        else if (inst[i] == 'W')
        {
            fx--;
        }
    }
    cin >> inst;
    for (int i = 0; i < m; i++)
    {
        b[i] = {bx, by};
        if (inst[i] == 'N')
        {
            by++;
        }
        else if (inst[i] == 'S')
        {
            by--;
        }
        else if (inst[i] == 'E')
        {
            bx++;
        }
        else if (inst[i] == 'W')
        {
            bx--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0 && i == 0)
            {
                continue;
            }
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
            dp[i][j] += dist(f[i], b[j]);
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}