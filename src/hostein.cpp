#include <iostream>
#include <vector>
using namespace std;
int v, g;
int r[30];
int f[20][30];
vector<int> p;
int a[20];
int ans = 1000000000;
void get_ans()
{
    int l[30] = {0};
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < v; j++)
        {
            l[j] += f[p[i]][j];
        }
    }
    bool ok = true;
    for (int i = 0; i < v; i++)
    {
        if (l[i] < r[i])
        {
            ok = false;
            break;
        }
    }
    if (ok && p.size() < ans)
    {
        ans = p.size();
        for (int i = 0; i < p.size(); i++)
        {
            a[i] = p[i];
        }
    }
}
void dfs(int s)
{
    if (s >= g)
    {
        get_ans();
        return;
    }
    p.push_back(s);
    dfs(s + 1);
    p.pop_back();
    dfs(s + 1);
}
int main()
{
    cin >> v;
    for (int i = 0; i < v; i++)
    {
        cin >> r[i];
    }
    cin >> g;
    for (int i = 0; i < g; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> f[i][j];
        }
    }
    dfs(0);
    cout << ans << " ";
    for (int i = 0; i < ans; i++)
    {
        cout << a[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}