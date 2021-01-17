#include <bits/stdc++.h>
using namespace std;
int n, k;
char m[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool v[105][105];
int conum(int x, int y, char c)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    bool v[105][105] = {false};
    v[x][y] = true;
    int cnt = 1;
    while (!q.empty())
    {
        int kx = q.front().first;
        int ky = q.front().second;
        for (int i = 0; i < 4; i++)
        {
            int nx = kx + dx[i];
            int ny = ky + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < 10 && !v[nx][ny] && m[nx][ny] == c)
            {
                v[nx][ny] = true;
                cnt++;
                q.push({nx, ny});
            }
        }
        q.pop();
    }
    return cnt;
}
void clear(int x, int y, char c)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    v[x][y] = true;
    m[x][y] = '0';
    while (!q.empty())
    {
        int kx = q.front().first;
        int ky = q.front().second;
        for (int i = 0; i < 4; i++)
        {
            int nx = kx + dx[i];
            int ny = ky + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < 10 && !v[nx][ny] && m[nx][ny] == c)
            {
                v[nx][ny] = true;
                m[nx][ny] = '0';
                q.push({nx, ny});
            }
        }
        q.pop();
    }
}
void mark(int x, int y, char c)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    v[x][y] = true;
    while (!q.empty())
    {
        int kx = q.front().first;
        int ky = q.front().second;
        for (int i = 0; i < 4; i++)
        {
            int nx = kx + dx[i];
            int ny = ky + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < 10 && !v[nx][ny] && m[nx][ny] == c)
            {
                v[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        q.pop();
    }
}
void maintain()
{
    for (int i = 0; i < 10; i++)
    {
        vector<char> p;
        for (int j = n - 1; j >= 0; j--)
        {
            if (m[j][i] != '0')
            {
                p.push_back(m[j][i]);
            }
        }
        for (int j = n - 1; j >= 0; j--)
        {
            m[j][i] = '0';
        }
        for (int j = 0; j < p.size(); j++)
        {
            m[n - 1 - j][i] = p[j];
        }
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << m[i][j];
        }
        cout << endl;
    }
}
int main()
{
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> m[i][j];
        }
    }
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                v[i][j] = false;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (!v[i][j] && m[i][j] != '0')
                {
                    int num = conum(i, j, m[i][j]);
                    if (num >= k)
                    {
                        cnt++;
                        clear(i, j, m[i][j]);
                    }
                    else
                    {
                        mark(i, j, m[i][j]);
                    }
                }
            }
        }
        maintain();
        if (cnt == 0)
        {
            break;
        }
    }
    print();
    return 0;
}