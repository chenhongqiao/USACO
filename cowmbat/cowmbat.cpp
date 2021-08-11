//Moortal Cowmbat
#include <bits/stdc++.h>
using namespace std;
int s[100005];
int dist[50][50];
long long dp[100005][50];
long long sc[100005][50];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        s[i] = c - 'a';
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> dist[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int a = 0; a < m; a++)
        {
            for (int b = 0; b < m; b++)
            {
                dist[a][b] = min(dist[a][b], dist[a][i] + dist[i][b]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            sc[k - 1][i] += dist[s[j]][i];
        }
        dp[k - 1][i] = sc[k - 1][i];
    }
    for (int i = k; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sc[i][j] = sc[i - 1][j] - dist[s[i - k]][j] + dist[s[i]][j];
        }
    }

    for (int i = k; i < n; i++)
    {
        long long tmin = 100000000005;
        if (i - k >= k - 1)
        {
            for (int j = 0; j < m; j++)
            {
                tmin = min(tmin, dp[i - k][j]);
            }
        }

        for (int j = 0; j < m; j++)
        {
            dp[i][j] = min(dp[i - 1][j] + dist[s[i]][j], tmin + sc[i][j]);
        }
    }
    long long ans = 100000000005;
    for (int i = 0; i < m; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans << endl;
    return 0;
}