#include <iostream>
#include <algorithm>
using namespace std;
int C[20005];
struct cow
{
    int a, b;
    bool g;
} N[20005];
bool cmp(const cow &a, const cow &b)
{
    return a.b < b.b;
}
int main()
{
    //freopen("helpcross.in", "r", stdin);
    //freopen("helpcross.out", "w", stdout);
    int c, n;
    cin >> c >> n;
    for (int i = 0; i < c; i++)
    {
        cin >> C[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> N[i].a >> N[i].b;
    }
    sort(C, C + c);
    sort(N, N + n, cmp);
    int ans = 0;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!N[j].g && N[j].a <= C[i] && N[j].b >= C[i])
            {
                ans++;
                N[j].g = true;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}