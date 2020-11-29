#include <iostream>
using namespace std;
struct nodes
{
    int f, ls, rs;
    bool v;
} s[10005];
int p, ns, t;
int plan[10005];
void dfs(int dep, int f)
{
    if (f == t)
    {
        cout << dep + 1 << endl;
        cout << 1 << endl;
        for (int i = 0; i < dep; i++)
        {
            cout << plan[i] << endl;
        }

        exit(0);
    }
    if (!s[f].v)
    {
        return;
    }
    plan[dep] = s[f].ls;
    dfs(dep + 1, s[f].ls);
    plan[dep] = s[f].rs;
    dfs(dep + 1, s[f].rs);
}
int main()
{
    cin >> p >> ns >> t;
    for (int i = 1; i <= ns; i++)
    {
        int tf, tls, trs;
        cin >> tf >> tls >> trs;
        s[tf].ls = tls;
        s[tf].f = tf;
        s[tf].rs = trs;
        s[tf].v = true;
    }
    dfs(0, 1);
}