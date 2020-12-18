#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int n, m, c;
int check(int v)
{
    int l = t[0];
    int cnt = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] - l > v || k == c)
        {
            k = 0;
            l = t[i];
            cnt++;
        }
        k++;
    }
    if (k != 0)
    {
        cnt++;
    }
    return cnt;
}
int main()
{
    //freopen("convention.in", "r", stdin);
    //freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        t.push_back(in);
    }
    sort(t.begin(), t.end());
    int h = 0, t = 1000000000;
    while (h < t - 1)
    {
        int p = (h + t + 1) / 2;
        int tmp = check(p);
        if (tmp <= m)
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