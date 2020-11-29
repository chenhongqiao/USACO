#include <iostream>
using namespace std;
int m[30][30];
int dp[30][30];
int main()
{
    int r;
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = m[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}