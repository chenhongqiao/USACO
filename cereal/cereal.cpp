#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
queue<int> q[300005];
struct cow
{
    int a, b;
    int loc = -1;
} c[200005];
bool rel[200005] = {false};
int main()
{
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> c[i].a >> c[i].b;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!rel[c[i].a])
        {
            ans++;
            rel[c[i].a] = true;
            c[i].loc = c[i].a;
            q[c[i].a].push(i);
        }
        else if (!rel[c[i].b])
        {
            ans++;
            rel[c[i].b] = true;
            c[i].loc = c[i].b;
            q[c[i].b].push(i);
            q[c[i].a].push(i);
        }
        else
        {
            q[c[i].a].push(i);
            q[c[i].b].push(i);
        }
    }
    cout << ans << endl;
    for (int i = 1; i < n; i++)
    {
        q[c[i].loc].pop();
        if (q[c[i].loc].empty())
        {
            ans--;
        }
        else
        {
            if (c[i].loc == c[q[c[i].loc].front()].a)
            {
                //cout << "a=" << q[c[i].loc].front() << endl;
                c[q[c[i].loc].front()].loc = c[i].loc;
                q[c[q[c[i].loc].front()].b].pop();
                if (q[c[q[c[i].loc].front()].b].empty())
                {
                    ans--;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}