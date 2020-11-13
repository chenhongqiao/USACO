#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<int> cv;
int b[10][350];
int func(int v, int dep)
{
    if (v == n)
    {
        return 1;
    }
    if (v > n)
    {
        return 0;
    }
    if (dep >= c)
    {
        return 0;
    }
    if (b[dep][v] != -1)
    {
        return b[dep][v];
    }
    int ans = 0;
    for (int i = 0;; i++)
    {
        if (v + i * cv[dep] > n)
        {
            break;
        }
        ans += func(v + i * cv[dep], dep + 1);
    }
    b[dep][v] = ans;
    return ans;
}
void init()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 350; j++)
        {
            b[i][j] = -1;
        }
    }
}
int main()
{
    cin >> n >> c;
    for (int i = 0; i < c; i++)
    {
        int in;
        cin >> in;
        cv.push_back(in);
    }
    init();
    cout << func(0, 0) << endl;
    return 0;
}