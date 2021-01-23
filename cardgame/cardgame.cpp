#include <bits/stdc++.h>
using namespace std;
vector<int> fe;
vector<int> se;
vector<int> b;
bool ev[100005];
bool rcomp(int a, int b)
{
    return a > b;
}
int main()
{
    //freopen("cardgame.in", "r", stdin);
    //freopen("cardgame.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n / 2; i++)
    {
        int num;
        cin >> num;
        ev[num] = true;
        fe.push_back(num);
    }
    for (int i = n / 2; i < n; i++)
    {
        int num;
        cin >> num;
        ev[num] = true;
        se.push_back(num);
    }
    for (int i = 1; i <= n * 2; i++)
    {
        if (!ev[i])
        {
            b.push_back(i);
        }
    }
    sort(b.begin(), b.end());
    sort(fe.begin(), fe.end(), rcomp);
    sort(se.begin(), se.end());
    int ans = 0;
    int h = n / 2, t = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (b[t] > fe[i])
        {
            ans++;
            t--;
        }
        else
        {
            h++;
        }
    }
    h = 0;
    t = n / 2 - 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (b[h] < se[i])
        {
            ans++;
            h++;
        }
        else
        {
            t--;
        }
    }
    cout << ans << endl;
    return 0;
}