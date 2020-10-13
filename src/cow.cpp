#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> c;
vector<int> o;
int wsum[100000];
int main()
{
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'C')
        {
            c.push_back(i);
        }
        else if (s[i] == 'O')
        {
            o.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            wsum[i] = wsum[i - 1];
        }
        if (s[i] == 'W')
        {
            wsum[i]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = upper_bound(o.begin(), o.end(), c[i]) - o.begin(); j < o.size(); j++)
        {
            ans += (wsum[n - 1] - wsum[o[j]]);
        }
    }
    cout << ans << endl;
    return 0;
}