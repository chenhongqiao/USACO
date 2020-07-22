#include <iostream>
using namespace std;
int w[25];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int m = 1;
    for (int i = 0; i < n; i++)
    {
        m *= 2;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int t[10] = {0};
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cnt++;
                int tmp = w[j];
                for (int k = 0; tmp > 0; k++)
                {
                    t[k] += tmp % 10;
                    tmp /= 10;
                }
            }
        }
        bool l = true;
        for (int j = 0; j < 10; j++)
        {
            if (t[j] >= 10)
            {
                l = false;
                break;
            }
        }
        if (l)
        {
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}