#include <bits/stdc++.h>
#define uset unordered_set
#define umap unordered_map
using namespace std;
int n;
char g[20][20];
int ans = 0;
uset<string> as;
umap<string, int> b;
string s;
int dfs(int x, int y, int dep)
{
    if (dep >= n && s[dep] != s[n * 2 - 2 - dep])
    {
        return 0;
    }
    if (dep == n - 1 && b.find(s) != b.end())
    {
        return b[s];
    }
    int tmp = 0;
    if (x + 1 < n)
    {
        s.push_back(g[x + 1][y]);
        tmp += dfs(x + 1, y, dep + 1);
        s.pop_back();
    }
    if (y + 1 < n)
    {
        s.push_back(g[x][y + 1]);
        tmp += dfs(x, y + 1, dep + 1);
        s.pop_back();
    }
    if (dep == n - 1)
    {
        b[s] = tmp;
    }
    if (dep >= n * 2 - 2)
    {
        if (as.find(s) == as.end())
        {
            ans++;
            as.insert(s);
        }
        return 1;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    s.push_back(g[0][0]);
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}