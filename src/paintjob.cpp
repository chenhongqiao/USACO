#include <bits/stdc++.h>
using namespace std;
unordered_set<int> nbs;
unordered_set<int> kbs;
map<int, bool> v;
int main()
{
    int a, b;
    int n, p;
    cin >> a >> b >> n >> p;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        tmp %= p;
        nbs.insert(tmp);
    }
    kbs.insert(a);
    int cnt = 0;
    while (1)
    {
        cnt++;
        int dif = 0;
        vector<int> pd;
        for (unordered_set<int>::iterator i = kbs.begin(); i != kbs.end(); i++)
        {
            pd.push_back(*i);
        }
        for (int i = 0; i < pd.size(); i++)
        {
            int in = (pd[i]);
            //kbs.erase(i);

            for (unordered_set<int>::iterator j = nbs.begin(); j != nbs.end(); j++)
            {
                int tmp = in * (*j);
                tmp %= p;
                if (tmp == b)
                {
                    cout << cnt << endl;
                    exit(0);
                }
                kbs.insert(tmp);
                if (!v[tmp])
                {
                    dif++;
                    v[tmp] = true;
                }
            }
        }
        if (dif == 0)
        {
            break;
        }
    }
    cout << -1 << endl;
    return 0;
}