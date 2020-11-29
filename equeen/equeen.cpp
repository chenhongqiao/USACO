#include <bits/stdc++.h>
using namespace std;
int ans = 0;
bool dv1[50];
bool dv2[50];
bool rv[20];
int n;
void func(int c)
{
    if (c >= n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!rv[i] && !dv1[i - c + 20] && !dv2[i + c])
        {
            rv[i] = true;
            dv1[i - c + 20] = true;
            dv2[i + c] = true;
            func(c + 1);
            rv[i] = false;
            dv1[i - c + 20] = false;
            dv2[i + c] = false;
        }
    }
}
int main()
{
    cin >> n;
    func(0);
    cout << ans << endl;
    return 0;
}