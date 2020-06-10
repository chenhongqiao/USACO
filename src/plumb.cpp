#include <iostream>
#include <algorithm>
using namespace std;
struct depth
{
    int n;
    int x, y;
} d[2505];
int m[55][55];
int n = 0;
bool cmp(const depth &a, const depth &b)
{
    return a.n > b.n;
}
bool verify(int p)
{
    int x = d[p].x;
    int y = d[p].y;
    int v = d[p].n;
    if (m[x + 1][y] == v || m[x - 1][y] == v || m[x][y + 1] == v || m[x][y - 1] == v || m[x + 1][y + 1] == v || m[x - 1][y - 1] == v || m[x - 1][y + 1] == v || m[x + 1][y - 1] == v)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            int tmp;
            cin >> tmp;
            m[i][j] = tmp;
            d[n].x = i;
            d[n].y = j;
            d[n].n = tmp;
            n++;
        }
    }
    sort(d, d + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (verify(i))
        {
            cout << d[i].n << endl;
            break;
        }
    }
    return EXIT_SUCCESS;
}