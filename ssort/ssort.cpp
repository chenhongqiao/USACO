#include <bits/stdc++.h>
using namespace std;
vector<int> s;
int n = 1;
int ans;
void func(int ah, int at, int bh, int bt)
{
    //at-ah should equal to bt-bh
    if (at - ah <= 0)
    {
        if (s[ah] > s[bh])
        {
            swap(s[bh], s[ah]);
            ans += 2;
        }
        return;
    }
    func(ah, ah + (at - ah + 1) / 2 - 1, ah + (at - ah + 1) / 2, at);
    func(bh, bh + (bt - bh + 1) / 2 - 1, bh + (bt - bh + 1) / 2, bt);
    bool need_swap = false;
    for (int i = 0; i < at - ah + 1; i++)
    {
        if (s[i + ah] > s[i + bh])
        {
            need_swap = true;
            break;
        }
        else if (s[i + ah] < s[i + bh])
        {
            break;
        }
    }
    if (need_swap)
    {
        ans += (at - ah + 1) * (at - ah + 1) * 2;
        vector<int> tmp;
        for (int i = ah; i <= at; i++)
        {
            tmp.push_back(s[i]);
        }
        for (int i = 0; i < at - ah + 1; i++)
        {
            s[i + ah] = s[i + bh];
        }
        for (int i = 0; i < at - ah + 1; i++)
        {
            s[i + bh] = tmp[i];
        }
    }
}
int main()
{
    int pwr;
    cin >> pwr;
    while (pwr > 0)
    {
        n *= 2;
        pwr--;
    }
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        s.push_back(in);
    }
    func(0, n / 2 - 1, n / 2, n - 1);
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}