#include <bits/stdc++.h>
using namespace std;
int n, s, e;
vector<vector<pair<int, int>>> r;
void parser(string s)
{
    vector<pair<int, int>> tmp;
    for (int i = 0; i < s.size(); i += 4)
    {
        if (s[i + 1] == 'x')
        {
            tmp.push_back({s[i] - '0', s[i + 2] - '0'});
        }
        else
        {
            tmp.push_back({(s[i] - '0') * 10 + (s[i + 1] - '0'), s[i + 3] - '0'});
            i++;
        }
    }
    r.push_back(tmp);
}
int t[10];
int ans = 0;
bool check()
{
    for (int i = 0; i < r.size(); i++)
    {
        bool ok = true;
        for (int j = 0; j < r[i].size(); j++)
        {
            if (t[r[i][j].second] < r[i][j].first)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            return true;
        }
    }
    return false;
}
string st;
void dfs(int dep)
{
    if (dep >= n)
    {
        if (check())
        {
            // cout << st << endl;
            ans++;
        }
        return;
    }
    for (int i = 1; i <= s; i++)
    {
        t[i]++;
        st.push_back(i + '0');
        dfs(dep + 1);
        st.pop_back();
        t[i]--;
    }
}
int main()
{
    cin >> n >> s >> e;
    for (int i = 0; i < e; i++)
    {
        string in;
        cin >> in;
        parser(in);
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}