// Tokitsukaze and Good 01-String
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> n;
        cin >> s;
        int cnt = 0;
        vector<int> l;
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && s[i - 1] != s[i])
            {
                l.push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        l.push_back(cnt);
        int ans1 = 0;
        for (int i = 0; i < l.size(); i++)
        {
            if (l[i] % 2 != 0)
            {
                ans1++;
                l[i]++;
                l[i + 1]--;
            }
        }
        int ans2 = 1;
        int lst = -1;
        for (int i = 0; i < n - 1; i += 2)
        {
            if (s[i] == s[i + 1])
            {
                if (lst != -1 && lst != s[i] - '0')
                {
                    ans2++;
                }
                lst = s[i] - '0';
            }
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}