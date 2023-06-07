// Dish Washing
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> d;
set<int> s;
short int t[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        d.push_back(in);
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i] < mx)
        {
            cout << i << endl;
            break;
        }
        auto c = s.upper_bound(d[i]);
        if (c == s.end())
        {
            t[d[i]] = -1;
            s.insert(d[i]);
        }
        else if (t[*c] == 1)
        {
            t[*c] = 0;
            s.erase(c);
            s.insert(d[i]);
            t[d[i]] = 1;
        }
        else if (t[*c] == -1 && (c == s.begin() || t[*next(c, -1)] == -1))
        {
            s.insert(d[i]);
            t[d[i]] = 1;
        }
        else
        {
            mx = *next(c, -1);
            for (auto j = s.begin(); j != c; j++)
            {
                t[*j] = 0;
            }
            s.erase(s.begin(), c);
            s.insert(d[i]);
            t[d[i]] = 1;
        }
    }
    if (mx == 0)
    {
        cout << 0 << endl;
    }
    return 0;
}