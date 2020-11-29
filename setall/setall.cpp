#include <iostream>
using namespace std;
int n, m;
int s[100005];
int c[100005];
void func(int dep)
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
    for (int i = 0; i < m; i++)
    {
        c[dep] = s[i];
        func(dep + 1);
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

    func(0);
    return 0;
}