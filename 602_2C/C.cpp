// Christmas Wreath
#include <iostream>
using namespace std;
int n;
bool vis[55][500][500];
int ans[55];
void dfs(int k, int sr, int sb)
{
    if (k == n)
    {
        if (sr == n * (n - 1) / 6 && sb == n * (n - 1) / 6 && (n * (n - 1) / 2) - sr - sb == n * (n - 1) / 6)
        {
            int asg[55][55];
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < i + 1; j++)
                {
                    asg[j][i + 1] = ans[i];
                }
            }
            cout << "Yes"
                 << "\n";
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (asg[i][j] == 0)
                    {
                        cout << 'W';
                    }
                    else if (asg[i][j] == 1)
                    {
                        cout << 'R';
                    }
                    else
                    {
                        cout << 'B';
                    }
                }
                cout << "\n";
            }
            exit(0);
        }
    }
    else
    {
        vis[k][sr][sb] = true;
        if (sr + k <= n * (n - 1) / 6 && !vis[k + 1][sr + k][sb])
        {
            ans[k] = 1;
            dfs(k + 1, sr + k, sb);
            ans[k] = 0;
        }
        if (sb + k <= n * (n - 1) / 6 && !vis[k + 1][sr][sb + k])
        {
            ans[k] = 2;
            dfs(k + 1, sr, sb + k);
            ans[k] = 0;
        }
        dfs(k + 1, sr, sb);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dfs(1, 0, 0);
    cout << "No"
         << "\n";
    return 0;
}