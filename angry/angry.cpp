#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> h;
int check(int r)
{
    int l = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] > l)
        {
            l = h[i] + 2 * r;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    //freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.push_back(x);
    }
    sort(h.begin(), h.end());
    int h = 0, t = 1000000000;
    while (h < t - 1)
    {
        int p = h + (t - h + 1) / 2;
        if (check(p) <= k)
        {
            t = p;
            continue;
        }
        else
        {
            h = p;
            continue;
        }
    }
    cout << t << endl;
    return 0;
}