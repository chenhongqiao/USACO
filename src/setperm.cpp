#include <iostream>
using namespace std;
int n, m;
int s[100005];
int c[100005];
bool u[100005];
void func(int dep, int l)
{
    if (dep >= n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << c[i];
        }
        cout << endl;
        return;
    }
    for (int i = l; i < m; i++)
    {
        if (!u[s[i]])
        {
            c[dep] = s[i];
            u[s[i]] = true;
            func(dep + 1, i);
            u[s[i]] = false;
        }
    }
}
int main()
{
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }
    cin >> n;

    func(0, 0);
    return 0;
}