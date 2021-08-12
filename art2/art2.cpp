//Modern Art 2
#include <bits/stdc++.h>
using namespace std;
int p[100005];
vector<int> rp;
stack<int> s;
int o[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int lst = -1;
    for (int i = 0; i < n; i++)
    {
        if (p[i] != lst)
        {
            lst = p[i];
            rp.push_back(p[i]);
            o[p[i]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < rp.size(); i++)
    {
        if (rp[i] == 0)
        {
            while (!s.empty())
            {
                s.pop();
            }
        }
        else if (!s.empty() && s.top() == rp[i])
        {
            o[rp[i]]--;
            if (o[rp[i]] == 0)
            {
                s.pop();
            }
        }
        else
        {
            o[rp[i]]--;
            if (o[rp[i]] == 0)
            {
                ans = max(ans, (int)s.size() + 1);
            }
            else
            {
                s.push(rp[i]);
            }
        }
    }
    if (s.size() > 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}