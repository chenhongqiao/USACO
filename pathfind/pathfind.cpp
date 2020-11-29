#include <bits/stdc++.h>
using namespace std;
short int rt[105][105];
queue<pair<int, int>> q;
vector<int> v[100005];
bool vis[105];
int main()
{
    int n, m;
    cin >> n >> m;
    m--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> rt[i][j];
        }
    }

    q.push({m, 0});
    vis[m] = true;
    int top = 0;
    while (!q.empty())
    {
        v[q.front().second].push_back(q.front().first);

        for (int i = 0; i < n; i++)
        {
            if (rt[q.front().first][i] && !vis[i])
            {
                vis[i] = true;
                q.push({i, q.front().second + 1});
                top = max(top, q.front().second + 1);
            }
        }
        q.pop();
    }
    for (int i = 0; i <= top; i++)
    {
        sort(v[i].begin(), v[i].end());
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}