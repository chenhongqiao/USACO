#include <iostream>
using namespace std;
int map[2005][2005];
long long sum[2005][2005];
int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            sum[i][j] = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1] + map[i][j];
        }
    }
    long long an = -1000000000, ax, ay;
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            long long tmp = sum[i][j] - sum[i + c][j] - sum[i][j + c] + sum[i + c][j + c];
            if (tmp > an)
            {
                an = tmp;
                ax = i;
                ay = j;
            }
        }
    }
    cout << ax << " " << ay << endl;
    return 0;
}