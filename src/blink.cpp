#include <bits/stdc++.h>
using namespace std;
int getbit(long long n, int p)
{
    return (n >> p) & 1;
}
void togglebit(long long *n, int p)
{
    *n ^= (1 << p);
}
map<long long, int> v;
vector<long long> s;
vector<long long> r;
int main()
{
    int n;
    long long b;
    cin >> n >> b;
    long long p = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        p *= 2;
        p += tmp;
    }
    int cnt = 1;
    v[p] = 1;
    s.push_back(p);
    int ld = -1;
    int ll = -1;
    while (cnt <= b)
    {
        cnt++;
        long long l = p;
        for (int i = 0; i < n; i++)
        {
            if (getbit(l, n - i - 1) == 1)
            {
                togglebit(&p, (n - i - 2 + n) % n);
            }
        }
        if (v[p] != 0)
        {
            ld = v[p];
            ll = cnt - v[p];
            break;
        }
        else
        {
            s.push_back(p);
            v[p] = cnt;
        }
    }
    long long ans;
    if (ld != -1)
    {
        for (int i = ld; i < cnt; i++)
        {
            r.push_back(s[i]);
        }
        ans = r[(b - ld) % ll];
    }
    else
    {
        ans = s[b];
    }
    for (int i = 0; i < n; i++)
    {
        if (getbit(ans, n - i - 1) == 1)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}