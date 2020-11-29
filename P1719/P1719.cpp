#include <iostream>
using namespace std;
int map[125][125];
int sum[125][125];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = i; k <= n; k++)
            {
                for (int l = j; l <= n; l++)
                {
                    ans = max(ans, sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
