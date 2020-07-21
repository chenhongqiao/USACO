#include <iostream>
using namespace std;
void solve()
{
    const int n = 20;
    int tb[25] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> tb[i];
    }
    const int m = 1048576;
    int ans = 1000000000;
    for (int i = 0; i < m; i++)
    {
        int o = 0;
        int b[25] = {0};
        for (int j = 0; j < n; j++)
        {
            b[j] = tb[j];
        }
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                o++;
                b[j] = 1 - b[j];
                if (j - 1 >= 0)
                {
                    b[j - 1] = 1 - b[j - 1];
                }
                if (j + 1 < n)
                {
                    b[j + 1] = 1 - b[j + 1];
                }
            }
        }
        bool ok = true;
        for (int j = 0; j < n; j++)
        {
            if (b[j] == 1)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            ans = min(ans, o);
        }
    }
    cout << ans << endl;
}
int main()
{
    solve();
}