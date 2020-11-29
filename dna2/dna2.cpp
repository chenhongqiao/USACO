#include <bits/stdc++.h>
using namespace std;
int n;
string s[10];
bool v[10];
int merge(string a, string b)
{
    for (int i = min(a.size(), b.size()); i >= 0; i--)
    {
        if (a.substr(a.size() - i) == b.substr(0, i))
        {
            return i;
        }
    }
}
int ans = 100000000;
void func(int dep, int len, string ns)
{
    if (dep >= n)
    {
        ans = min(ans, len);
        //cout << ns << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            v[i] = true;
            int mg = merge(ns, s[i]);
            func(dep + 1, len + s[i].size() - mg, ns + s[i].substr(mg));
            v[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    func(0, 0, "");
    cout << ans << endl;
    return 0;
}