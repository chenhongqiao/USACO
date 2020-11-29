#include <iostream>
using namespace std;
int n;
int plan[20];
int cnt;
void dfs(int s, int n0, int n1)
{
    if (s >= n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << plan[i];
        }
        cout << endl;
        cnt++;
        return;
    }
    if (n0 < (n + 1) / 2 - 1)
    {
        plan[s] = 0;
        dfs(s + 1, n0 + 1, n1);
    }
    plan[s] = 1;
    dfs(s + 1, n0, n1 + 1);
}
int main()
{
    cin >> n;
    dfs(0, 0, 0);
    cout << cnt << endl;
    return 0;
}