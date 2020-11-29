#include <bits/stdc++.h>
using namespace std;
string p[55];
map<string, int> mp;
int ans = 0;
int n, m;
void func(int x, int y)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (x + i >= 0 && x + i < n && y + j >= 0 && y + j < m)
            {
                string t;
                t += p[x][y];
                t += p[x + i][y + j];
                t += p[x + i * 2][y + j * 2];
                if (t[0] != t[1] && t[1] == t[2] && t[0] != 'M' && t[1] != 'O')
                {
                    mp[t]++;
                    ans = max(ans, mp[t]);
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            func(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}