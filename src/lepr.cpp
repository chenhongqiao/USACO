#include <iostream>
using namespace std;
int m[205][205];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    int ans = -1000000000;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp = 0;
            for (int k = 0; k < n; k++)
            {

                tmp += m[(i + k) % n][j];
                if (k != 0 && tmp < 0)
                {
                    break;
                }
                ans = max(ans, tmp);
            }
            tmp = 0;
            for (int k = 0; k < n; k++)
            {

                tmp += m[i][(j + k) % n];
                if (k != 0 && tmp < 0)
                {
                    break;
                }
                ans = max(ans, tmp);
            }
            tmp = 0;
            for (int k = 0; k < n; k++)
            {

                tmp += m[(i + k) % n][(j + k) % n];
                if (k != 0 && tmp < 0)
                {
                    break;
                }
                ans = max(ans, tmp);
            }
            tmp = 0;
            for (int k = 0; k < n; k++)
            {

                tmp += m[(i - k + n) % n][(j + k) % n];
                if (k != 0 && tmp < 0)
                {
                    break;
                }
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}