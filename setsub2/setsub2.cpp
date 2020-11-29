#include <iostream>
using namespace std;
int d[1005];
void dfs(int dep, const int n)
{
    if (dep >= n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << d[i];
        }

        cout << endl;
        return;
    }

    d[dep] = 0;
    dfs(dep + 1, n);
    d[dep] = 1;
    dfs(dep + 1, n);
}
int main()
{
    int n;
    cin >> n;
    dfs(0, n);
    return 0;
}