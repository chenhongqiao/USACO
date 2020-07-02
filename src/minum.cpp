#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int l, n;
string p;
string c[30];
bool u[30];
vector<string> plan;
vector<string> propose;
void dfs(int s, int nl)
{
    if (nl >= l)
    {
        string s;
        for (int i = 0; i < plan.size(); i++)
        {
            s += plan[i];
        }
        propose.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        if (!u[i])
        {
            bool ok = true;
            for (int j = 0; j < c[i].size(); j++)
            {
                if (p[j + nl] != '?' && c[i][j] != p[j + nl])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                u[i] = true;
                plan.push_back(c[i]);
                dfs(s + 1, nl + c[i].size());
                u[i] = false;
                plan.pop_back();
            }
        }
    }
}
int main()
{
    cin >> l >> n;
    cin >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c, c + n);
    dfs(0, 0);
    if (propose.size() == 0)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        sort(propose.begin(), propose.end());
        cout << propose[0] << endl;
    }
    return 0;
}