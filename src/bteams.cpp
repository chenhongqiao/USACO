#include <iostream>
using namespace std;
int p[15];
bool u[15];
int tp[10];
const int n = 12;
int ans = 100000000;
void get_ans()
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (!u[i])
        {
            tp[3] += p[i];
            a++;
        }
    }
    if (a != 3)
    {
        return;
    }
    ans = min(ans, max(tp[0], max(tp[1], max(tp[2], tp[3]))) - min(tp[0], min(tp[1], min(tp[2], tp[3]))));
    if (max(tp[0], max(tp[1], max(tp[2], tp[3]))) - min(tp[0], min(tp[1], min(tp[2], tp[3]))) == 0)
        cout << tp[0] << " " << tp[1] << " " << tp[2] << " " << tp[3] << endl;
    tp[3] = 0;
}
void func(int dep, int v, int c, int t)
{
    if (dep >= n || c >= 3)
    {
        if (c == 3)
        {
            if (t < 3)
            {
                tp[t] = v;
                func(0, 0, 0, t + 1);
            }
            else
            {
                get_ans();
            }
        }
        return;
    }
    func(dep + 1, v, c, t);
    if (!u[dep] && c < 3)
    {
        u[dep] = true;
        func(dep + 1, v + p[dep], c + 1, t);
        u[dep] = false;
    }
}

int main()
{

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    func(0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}