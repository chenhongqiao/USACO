#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string t;
    cin >> s >> t;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        ans += s[i];
        int asize = ans.size();
        int tsize = t.size();
        if (ans.substr((asize - tsize) > 0 ? (asize - tsize) : 0) == t)
        {
            ans = ans.substr(0, ans.size() - t.size());
        }
    }
    cout << ans << endl;
    return 0;
}