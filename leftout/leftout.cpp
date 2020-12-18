#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
string g[1005];
umap<string, int> m;
umap<string, int> p;
string reverse(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
        {
            s[i] = 'L';
        }
        else if (s[i] == 'L')
        {
            s[i] = 'R';
        }
    }
    return s;
}
int diff(string b, string o)
{
    int cnt = 0;
    int f;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] != o[i])
        {
            cnt++;
            f = i;
        }
    }
    if (cnt == 0 || cnt > 1)
    {
        return -1;
    }
    else
    {
        return f;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    for (int i = 0; i < n; i++)
    {
        m[g[i]]++;
        m[reverse(g[i])]++;
        p[g[i]] = i;
        p[reverse(g[i])] = i;
    }
    if (m.size() == 2 || m.size() > 4)
    {
        cout << "-1" << endl;
        return 0;
    }

    pair<int, int> ans = {10000, 10000};
    if (n == 2)
    {
        for (auto i = m.begin(); i != m.end(); i++)
        {
            for (auto j = m.begin(); j != m.end(); j++)
            {
                int x = p[j->first];
                int y = diff(i->first, j->first);
                if (y != -1)
                {
                    if (x < ans.first || (x == ans.first && y < ans.second))
                    {
                        ans.first = x;
                        ans.second = y;
                    }
                }
            }
        }
    }
    else
    {
        for (auto i = m.begin(); i != m.end(); i++)
        {
            for (auto j = m.begin(); j != m.end(); j++)
            {
                if (i->second > 1 && j->second == 1)
                {
                    int x = p[j->first];
                    int y = diff(i->first, j->first);
                    if (y != -1)
                    {
                        if (x < ans.first || (x == ans.first && y < ans.second))
                        {
                            ans.first = x;
                            ans.second = y;
                        }
                    }
                }
            }
        }
    }
    cout << ans.first + 1 << " " << ans.second + 1 << endl;
    return 0;
}