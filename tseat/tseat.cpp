#include <bits/stdc++.h>
using namespace std;
struct seat
{
    int x, y;
    long long d;
} s[5100];
bool cmp(const seat &a, const seat &b)
{
    if (a.d != b.d)
    {
        return a.d < b.d;
    }
    else
    {
        if (a.x != b.x)
        {
            return a.x > b.x;
        }
        else
        {
            return a.y < b.y;
        }
    }
}
int main()
{
    int w, r;
    cin >> w >> r;
    int bx = r - 1;
    int by = w / 2;
    int n = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < w; j++)
        {
            s[n].x = i;
            s[n].y = j;
            s[n].d = abs(i - bx) * abs(i - bx) + abs(j - by) * abs(j - by);
            n++;
        }
    }
    sort(s, s + n, cmp);
    int ans[55][110];
    for (int i = 0; i < n; i++)
    {
        ans[s[i].x][s[i].y] = i + 1;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}