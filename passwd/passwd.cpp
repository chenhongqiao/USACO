#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char w[30];
bool u[30];
char plan[30];
void dfs(int dep, int last)
{
    if (dep >= l)
    {
        int o = 0, no = 0;
        for (int i = 0; i < l; i++)
        {
            if (plan[i] == 'a' || plan[i] == 'e' || plan[i] == 'i' || plan[i] == 'o' || plan[i] == 'u')
            {
                o++;
            }
            else
            {
                no++;
            }
        }
        if (o >= 1 && no >= 2)
        {
            for (int i = 0; i < l; i++)
            {
                cout << plan[i];
            }
            cout << endl;
        }
        return;
    }
    for (int i = last; i < c; i++)
    {
        if (!u[i])
        {
            u[i] = true;
            plan[dep] = w[i];
            dfs(dep + 1, i);
            u[i] = false;
        }
    }
}
int main()
{
    cin >> l >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> w[i];
    }
    sort(w, w + c);
    dfs(0, 0);
    return 0;
}