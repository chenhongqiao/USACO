#include <bits/stdc++.h>
using namespace std;
int v[10][10];
int ans = 0;
int n;
void dfs(int i, int j, int cnt)
{
    if (i == 0 && j == n - 1)
    {
        ans = max(ans, cnt + v[i][j]);
        return;
    }
    if (i < 0 || j < 0 || i >= n || j >= n)
    {
        return;
    }
    dfs(i - 1, j, cnt + v[i][j]);
    dfs(i, j + 1, cnt + v[i][j]);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char cm;
            char s;
            cin >> cm >> s;
            int cv;
            switch (cm)
            {
            case 'A':
                cv = 1;
                break;
            case 'T':
                cv = 10;
                break;
            case 'J':
                cv = 11;
                break;
            case 'Q':
                cv = 12;
                break;
            case 'K':
                cv = 13;
                break;
            default:
                cv = cm - '0';
                break;
            }
            v[i][j] = cv;
        }
    }
    dfs(n - 1, 0, 0);
    cout << ans << endl;
    return 0;
}