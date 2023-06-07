// Uddered But Not Herd
#include <iostream>
#include <vector>
#include <map>
using namespace std;
string in;
vector<int> s;
map<char, int> mp;
int c[30][30];
int dp[2200000];
int main()
{
    cin >> in;
    int n = 0;
    for (int i = 0; i < in.size(); i++)
    {
        if (mp.find(in[i]) != mp.end())
        {
            s.push_back(mp[in[i]]);
        }
        else
        {
            s.push_back(n);
            mp[in[i]] = n;
            n++;
        }
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        c[s[i]][s[i + 1]]++;
    }
    for (int set = 0; set < (1 << n); set++)
    {
        int ans = 1000000000;
        for (int i = 0; i < n; i++)
        {
            if (set & (1 << i))
            {
                int nset = set & ~(1 << i);
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (set & (1 << j))
                    {
                        cnt += c[i][j];
                    }
                }
                ans = min(ans, dp[nset] + cnt);
            }
        }
        if (ans == 1000000000)
        {
            dp[set] = 0;
        }
        else
        {
            dp[set] = ans;
        }
    }
    cout << dp[(1 << n) - 1] + 1 << endl;
    return 0;
}