// Tests for Haybales
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> g[100005];
pair<int, int> ans[100005];
int cnt = 0;
void dfs(int cur, int dep)
{
    for (int child : g[cur])
    {
        dfs(child, dep - 1);
    }
    ans[cur] = make_pair(dep, cnt);
    cnt++;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        g[v].push_back(i);
    }
    dfs(n, n);
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << (long long)ans[i].first * n + ans[i].second << endl;
    }
    return 0;
}