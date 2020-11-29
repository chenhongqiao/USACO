#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
using namespace std;
umap<int, uset<int>> r;
umap<int, uset<int>> c;
umap<int, int> rm;
umap<int, int> cm;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        r[x].insert(y);
        c[y].insert(x);
    }
    for (auto i = r.begin(); i != r.end(); i++)
    {
        int cnt = 0;
        for (auto j = i->second.begin(); j != i->second.end(); j++)
        {
            if (c[*j].size() == 1)
            {
                cnt++;
            }
        }
        rm[i->first] = cnt;
    }
    for (auto i = c.begin(); i != c.end(); i++)
    {
        int cnt = 0;
        for (auto j = i->second.begin(); j != i->second.end(); j++)
        {
            if (r[*j].size() == 1)
            {
                cnt++;
            }
        }
        cm[i->first] = cnt;
    }
    bool yes = false;
    if (r.size() <= 3 || c.size() <= 3)
    {
        yes = true;
    }
    else
    {
        for (auto i = rm.begin(); i != rm.end(); i++)
        {
            if (c.size() - i->second <= 2)
            {
                yes = true;
                break;
            }
        }
        for (auto i = cm.begin(); i != cm.end(); i++)
        {
            if (r.size() - i->second <= 2)
            {
                yes = true;
                break;
            }
        }
    }
    cout << yes << endl;
    return 0;
}