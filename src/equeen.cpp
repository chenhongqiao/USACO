#include <bits/stdc++.h>
using namespace std;
int ans = 0;
bool dv1[20];
bool dv2[20];
bool rv[10];
void func(int c)
{
    if (c >= 8)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (!rv[i] && !dv1[i - c + 10] && !dv2[i + c])
        {
            rv[i] = true;
            dv1[i - c + 10] = true;
            dv2[i + c] = true;
            func(c + 1);
            rv[i] = false;
            dv1[i - c + 10] = false;
            dv2[i + c] = false;
        }
    }
}
int main()
{
    func(0);
    cout << ans << endl;
    return 0;
}