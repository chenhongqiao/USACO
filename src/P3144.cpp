#include <iostream>
#include <vector>
using namespace std;
vector<int> G[3005];
int n, m;
bool rem[3005];
void bfs(int vis[])
{
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        rem[tmp] = true;
    }
}