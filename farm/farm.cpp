#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, q;
struct operation
{
    char o;
    int a, b;
};
vector<operation> op;
vector<int> g[100005];
bool actv[100005];
int admp[200005];
bool tbrm[200005];
int ans[100005];
void bfs(int f, int stp)
{
    queue<int> q;
    q.push(f);
    actv[f] = true;
    ans[f] = max(ans[f], stp);
    while (!q.empty())
    {
        int k = q.front();
        for (auto adj : g[k])
        {
            if (!actv[adj])
            {
                actv[adj] = true;
                ans[adj] = max(ans[adj], stp);
                q.push(adj);
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> n >> q;
    int cnt = 1;
    for (int i = 0; i < q; i++)
    {
        char o;
        int a, b;
        cin >> o;
        if (o == 'D')
        {
            cin >> a;
            op.push_back({o, a, -1});
        }
        else if (o == 'A')
        {
            cin >> a >> b;
            op.push_back({o, a, b});
            admp[cnt] = i;
            cnt++;
        }
        else if (o == 'R')
        {
            cin >> a;
            op.push_back({o, a, -1});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        actv[i] = true;
    }
    for (int i = 0; i < q; i++)
    {
        if (op[i].o == 'D')
        {
            actv[op[i].a] = false;
        }
        else if (op[i].o == 'R')
        {
            tbrm[admp[op[i].a]] = true;
        }
    }
    for (int i = 0; i < q; i++)
    {
        if (op[i].o == 'A' && !tbrm[i])
        {
            g[op[i].a].push_back(op[i].b);
            g[op[i].b].push_back(op[i].a);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (actv[i])
        {
            bfs(i, q);
        }
    }
    for (int i = q - 1; i >= 0; i--)
    {
        if (op[i].o == 'D')
        {
            bfs(op[i].a, i);
        }
        else if (op[i].o == 'R')
        {
            operation ka = op[admp[op[i].a]];
            g[ka.a].push_back(ka.b);
            g[ka.b].push_back(ka.a);
            if (actv[ka.a])
            {
                bfs(ka.a, i);
            }
            else if (actv[ka.b])
            {
                bfs(ka.b, i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}