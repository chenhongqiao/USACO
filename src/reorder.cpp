#include <iostream>
using namespace std;
int a[105];
int b[105];
int ba[105];
bool h[105];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        b[tmp] = i;
        ba[i] = tmp;
    }
    int ansa = 0;
    int ansb = -1;
    int c[1005];
    for (int j = 0; j < n; j++)
    {
        c[j] = a[j];
    }
    for (int i = 0; i < n; i++)
    {
        if (h[a[i]])
        {
            continue;
        }
        int t = a[i];
        c[i] = -1;
        int st = 0;
        bool dis = false;
        h[t] = true;
        while (t != -1)
        {
            if (st > n)
            {
                dis = true;
                break;
            }
            h[t] = true;
            int tmp = c[b[t]];
            c[b[t]] = t;
            t = tmp;
            st++;
        }
        if (c[i] != -1 && !dis)
        {
            ansb = max(ansb, st);
        }
        bool d = true;
        for (int j = 0; j < n; j++)
        {
            if (c[j] != b[j])
            {
                d = false;
                break;
            }
        }
        if (d)
        {
            break;
        }
        else if (st != 1)
        {
            ansa++;
        }
    }
    if (ansa == 0)
    {
        cout << 0 << " " << -1 << endl;
    }
    else
    {
        cout << ansa << " " << ansb << endl;
    }
    return 0;
}