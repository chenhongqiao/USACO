#include <iostream>
#include <algorithm>
using namespace std;
void solve()
{
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first < b.first;
        }
    };
    pair<int, int> h[25];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i].first >> h[i].second;
    }
    sort(h, h + n, cmp);
    int m = 1;
    for (int i = 0; i < n; i++)
    {
        m *= 2;
    }
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        int tmp = 0;
        int q[25] = {0};
        int qh = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                //cout << 1;
                q[qh] = h[j].second;
                qh++;
            }
            /*else
            {
                cout << 0;
            }*/
        }
        bool ok = true;
        for (int j = 0; j < qh - 1; j++)
        {
            if (q[j] >= q[j + 1])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            ans = max(ans, qh);
        }

        //cout << endl;
    }
    cout << ans << endl;
}
int main()
{
    solve();
}