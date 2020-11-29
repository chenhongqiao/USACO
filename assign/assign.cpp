#include <iostream>
using namespace std;
struct rules
{
    int a, b;
    char d;
} r[55];
int p[20];
int n, k;
int ans = 0;
void dfs(int dep)
{
    if (dep > n)
    {
        bool ok = true;
        for (int i = 0; i < k; i++)
        {
            if (r[i].d == 'S')
            {
                if (p[r[i].a] != p[r[i].b])
                {
                    ok = false;
                    break;
                }
            }
            else if (r[i].d == 'D')
            {
                if (p[r[i].a] == p[r[i].b])
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
        {
            ans++;
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        p[dep] = i;
        dfs(dep + 1);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> r[i].d >> r[i].a >> r[i].b;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}