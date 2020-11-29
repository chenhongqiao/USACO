#include <iostream>
#include <vector>
using namespace std;
struct cow
{
    int l, m;
    vector<int> a;
} c[1005];
vector<int> q[1000005];
bool r[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].l >> c[i].m;
        for (int j = 0; j < c[i].m; j++)
        {
            int tmp;
            cin >> tmp;
            c[i].a.push_back(tmp);
        }
    }
    int t = 0;
    q[c[0].l].push_back(0);
    r[0] = true;
    int p = 1;
    while (1)
    {
        if (!q[t].empty())
        {
            int k = 0;
            while (k < q[t].size())
            {
                p--;
                for (int i = 0; i < c[q[t][k]].m; i++)
                {
                    int s = c[q[t][k]].a[i] - 1;
                    if (!r[s])
                    {
                        p++;
                        q[t + c[s].l].push_back(s);
                        r[s] = true;
                    }
                }
                k++;
            }
            if (p == 0)
            {
                break;
            }
        }
        t++;
    }
    cout << t << endl;
    return 0;
}