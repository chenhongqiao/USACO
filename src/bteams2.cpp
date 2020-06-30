#include <iostream>
#include <chrono>
using namespace std;
int p[15];
bool u[15];
int plan[15];
const int n = 12;
int cnt = 0;
int ans = 100000000;
void get_ans()
{
    cnt++;
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    p1 = plan[0] + plan[1] + plan[2];
    p2 = plan[3] + plan[4] + plan[5];
    p3 = plan[6] + plan[7] + plan[8];
    p4 = plan[9] + plan[10] + plan[11];

    ans = min(ans, max(p1, max(p2, max(p3, p4))) - min(p1, min(p2, min(p3, p4))));
}
void func(int dep, int l)
{
    if (dep >= n)
    {
        get_ans();
        return;
    }
    if (dep % 3 == 0)
    {
        l = 0;
    }
    for (int i = l; i < n; i++)
    {
        if (!u[i])
        {
            u[i] = true;
            plan[dep] = p[i];
            func(dep + 1, i);
            u[i] = false;
        }
    }
}

int main()
{
    freopen("test", "r", stdin);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    auto begin = chrono::high_resolution_clock::now();
    func(0, 0);
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(chrono::high_resolution_clock::now() - begin).count();
    cout << "time used=" << dur << " ms" << endl;
    cout << ans << " " << cnt << endl;
    return 0;
}