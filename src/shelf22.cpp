#include <iostream>
using namespace std;
void solve()
{
    int n, b;
    int h[25];
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int s = 0;
    int m = 1;
    for (int i = 0; i < n; i++)
    {
        m *= 2;
    }
    int ans = 1000000000;
    for (int i = 0; i < m; i++)
    {
        int tmp = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                //cout << 1;
                tmp += h[n - j - 1];
            }
            /*else
            {
                cout << 0;
            }*/
        }
        //cout << endl;
        if (tmp >= b)
        {
            ans = min(ans, tmp - b);
        }
    }
    cout << ans << endl;
}
int main()
{
    solve();
}