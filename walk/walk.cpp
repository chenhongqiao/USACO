// I Would Walk 500 Miles
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long g[7505];
vector<int> ans;
bool vis[7505];
long long calc_dis(int x, int y)
{
    if (x > y)
    {
        swap(x, y);
    }
    return ((long long)x * 2019201913 + (long long)y * 2019201949) % 2019201997;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        g[i] = 100000000000005;
    }
    g[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        long long vw = 100000000000005;
        int v = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && g[j] < vw)
            {
                v = j;
                vw = g[j];
            }
        }
        vis[v] = true;
        if (v != 1)
        {
            ans.push_back(vw);
        }
        for (int j = 1; j <= n; j++)
        {
            g[j] = min(g[j], calc_dis(v, j));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[n - k] << endl;
    return 0;
}