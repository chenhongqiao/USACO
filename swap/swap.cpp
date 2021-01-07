#include <cstdio>
#include <vector>

using namespace std;
struct orders
{
    int s, e;
} o[105];

void setIO()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
};

int main()
{
    //setIO();
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &o[i].s, &o[i].e);
    }
    int init[100005];
    for (int i = 1; i <= n; ++i)
    {
        init[i] = i;
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = o[i].s; j <= o[i].s + (o[i].e - o[i].s) / 2; ++j)
        {
            int tmp = init[j];
            init[j] = init[o[i].e - (j - o[i].s)];
            init[o[i].e - (j - o[i].s)] = tmp;
        }
    }
    int ans[100005] = {0};
    bool vis[100005] = {false};
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        vector<int> map;
        map.push_back(i);
        int cur = init[i];
        while (true)
        {
            if (cur == i)
            {
                //cout << "match" << endl;
                ans[i] = map[k % map.size()];
                break;
            }
            map.push_back(cur);
            cur = init[cur];
        }
        int rot = k % map.size();
        for (int j = 1; j < map.size(); ++j)
        {
            vis[map[j]] = true;
            ans[map[j]] = map[(j + rot) % map.size()];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}