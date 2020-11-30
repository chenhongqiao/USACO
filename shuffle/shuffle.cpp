#include <bits/stdc++.h>
using namespace std;
int r[100005];
bool v[100005];
int main()
{
    //freopen("shuffle.in", "r", stdin);
    //freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            int c = i;
            queue<int> q;
            while (!v[c])
            {
                q.push(c);
                v[c] = true;
                c = r[c];
            }
            bool t = false;
            while (!q.empty())
            {
                if (q.front() == c)
                {
                    t = true;
                }
                if (t)
                {
                    ans++;
                }
                q.pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}