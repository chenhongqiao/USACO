// CSES Problem Set Concert Tickets
#include <bits/stdc++.h>
using namespace std;
multiset<int> p;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int cp;
        cin >> cp;
        p.insert(cp);
    }
    for (int i = 0; i < m; i++)
    {
        int w;
        cin >> w;
        auto t = p.upper_bound(w);
        if (t != p.begin())
        {
            t--;
            if (t == p.end())
            {
                cout << -1 << endl;
            }
            else
            {

                cout << *t << endl;
                p.erase(t);
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}