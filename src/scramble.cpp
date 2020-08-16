#include <bits/stdc++.h>
using namespace std;
int ansb[50005];
int answ[50005];
struct cow
{
    string n;
    string r;
    int id;
} c[50005];
bool cmp1(const cow &a, const cow &b)
{
    return a.r < b.r;
}
bool cmp2(const cow &a, const cow &b)
{
    return a.n < b.n;
}
bool cmpl1(const cow &a, string b)
{
    return a.r < b;
}
bool cmpl2(const cow &a, string b)
{
    return a.n < b;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].n;
        c[i].id = i;
        sort(c[i].n.begin(), c[i].n.end());
        c[i].r = c[i].n;
        reverse(c[i].r.begin(), c[i].r.end());
    }

    sort(c, c + n, cmp1);
    for (int i = 0; i < n; i++)
    {
        int tmp = lower_bound(c, c + n, c[i].n, cmpl1) - c;
        if (tmp <= i)
        {
            ansb[c[i].id] = tmp;
        }
        else
        {
            ansb[c[i].id] = tmp - 1;
        }
    }

    sort(c, c + n, cmp2);
    for (int i = 0; i < n; i++)
    {
        int tmp = lower_bound(c, c + n, c[i].r, cmpl2) - c;
        if (tmp <= i)
        {
            answ[c[i].id] = tmp;
        }
        else
        {
            answ[c[i].id] = tmp - 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ansb[i] + 1 << " " << answ[i] + 1 << endl;
    }
    return 0;
}