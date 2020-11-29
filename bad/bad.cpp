#include <iostream>
using namespace std;
bool vis[10005];
int func(int n)
{
    int tmp = (n / 10) % 10 + ((n / 100) % 10) * 10;
    tmp *= tmp;
    if (vis[tmp])
    {
        return 1;
    }
    else
    {
        vis[tmp] = true;
        return func(tmp) + 1;
    }
}
int main()
{
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}