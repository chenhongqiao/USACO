#include <bits/stdc++.h>
using namespace std;
int dist[55][50005];
int b[50005];
int adj[55][55];
deque<pair<int, int>> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            char c;
            cin >> c;
            if (c == '1')
            {
                adj[i][j] = true;
            }
        }
    }
    dist[b[0]][0] = 0;
    q.push_back({b[0], 0});
    while (!q.empty())
    {
        int ob = q.front().first;
        int kp = q.front().second;
        q.pop_front();
        int kb = b[kp];
        if (kp != 0 && dist[ob][kp - 1] == -1)
        {
            q.push_back({ob, kp - 1});
            dist[ob][kp - 1] = dist[ob][kp] + 1;
        }
        if (kp != n - 1 && dist[ob][kp + 1] == -1)
        {
            q.push_back({ob, kp + 1});
            if (kp + 1 != n - 1 || ob != b[n - 1])
            {
                dist[ob][kp + 1] = dist[ob][kp] + 1;
            }
        }
        if (adj[ob][kb] && dist[kb][kp] == -1)
        {
            q.push_front({kb, kp});
            dist[kb][kp] = dist[ob][kp];
        }
    }
    cout << dist[b[n - 1]][n - 1] << endl;
    return 0;
}