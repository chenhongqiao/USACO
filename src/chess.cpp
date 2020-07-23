#include <iostream>
using namespace std;
int n, k;
char c[2005][2005];
int fc[2005][2005];
int fr[2005][2005];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                fr[i][j] = fr[i][j - 1];
            }
            if (c[i][j] == 'B')
            {
                fr[i][j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                fc[i][j] = fc[i][j - 1];
            }
            if (c[j][i] == 'B')
            {
                fc[i][j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(fc[i][j] + fr[j][i], ans);
        }
    }
    cout << ans << endl;
    return 0;
}